// Fill out your copyright notice in the Description page of Project Settings.


#include "NLProjectileTask.h"

bool UNLProjectileTask::CanStart(float CurrentTime)
{
    if (__StartTime <= CurrentTime)
    {
        return true;
    }

    return false;
}

bool UNLProjectileTask::CanEnd(float CurrentTime)
{
    if (CurrentTime >= __EndTime)
    {
        return true;
    }

    return false;
}

void UNLProjectileTask::StartTask(UNLPJTAbilityContext* InAbilityContext)
{

}

void UNLProjectileTask::ExecuteTask(UNLPJTAbilityContext* InAbilityContext)
{

}

void UNLProjectileTask::EndTask(UNLPJTAbilityContext* InAbilityContext)
{

}
