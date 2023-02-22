// Fill out your copyright notice in the Description page of Project Settings.


#include "NLProjectileInstance.h"
#include "NLProjectileAbility.h"
#include "NLProjectileTask.h"
#include "NLPJTAbilityContext.h"

void UNLProjectileInstance::OnStart(AActor* InOwner, TSubclassOf<UNLProjectileAbility> InAbility)
{
    if (InAbility == nullptr || InAbility->IsValidLowLevel() == false)
    {
        return;
    }

    __Ability = InAbility.GetDefaultObject();

    __AllTaskList = __Ability->GetTaskList();

    __AbilityContext = NewObject<UNLPJTAbilityContext>(this);

    __AbilityContext->Owner = InOwner;
}

void UNLProjectileInstance::OnUpdate(float DeltaTime)
{
    if (__Ability == nullptr || __Ability->IsValidLowLevel() == false)
    {
        return;
    }

    for (int i = 0; i < __AllTaskList.Num();)
    {
        UNLProjectileTask* Task = __AllTaskList[i];
        if (Task == nullptr || Task->IsValidLowLevel() == false)
        {
            continue;
        }

        bool bStart = Task->CanStart(__CurrentTime);
        if (bStart)
        {
            Task->StartTask(__AbilityContext);

            __ActiveTaskList.Add(Task);
            __AllTaskList.RemoveAt(i);
            continue;
        }

        ++i;
    }

    for (int i = 0; i < __ActiveTaskList.Num();)
    {
        UNLProjectileTask* Task = __ActiveTaskList[i];
        if (Task == nullptr || Task->IsValidLowLevel() == false)
        {
            continue;
        }

        Task->ExecuteTask(__AbilityContext);

        bool bEnd = Task->CanEnd(__CurrentTime);
        if (bEnd)
        {
            Task->EndTask(__AbilityContext);
            __ActiveTaskList.RemoveAt(i);
            continue;
        }

        ++i;
    }

    __CurrentTime += DeltaTime;

    if (__CurrentTime >= __Ability->GetTimeLength())
    {
        OnEnd();
        return;
    }
}

void UNLProjectileInstance::OnEnd()
{

}
