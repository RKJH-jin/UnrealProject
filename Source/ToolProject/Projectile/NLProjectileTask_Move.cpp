// Fill out your copyright notice in the Description page of Project Settings.

#include "NLProjectileTask_Move.h"
#include "Projectile/NLPJTAbilityContext.h"
#include "Projectile/NLProjectileInterface.h"

void UNLProjectileTask_Move::StartTask(UNLPJTAbilityContext* InAbilityContext)
{
    Super::StartTask(InAbilityContext);

    if (InAbilityContext == nullptr)
    {
        return;
    }

    AActor* Owner = InAbilityContext->Owner.Get();
    if (Owner == nullptr || Owner->IsValidLowLevel() == false)
    {
        return;
    }

    if (Owner->GetClass()->ImplementsInterface(UNLProjectileInterface::StaticClass()))
    {
        INLProjectileInterface::Execute_StartMoveTask(Owner, __MoveType, __Speed, __GravityScale);
    }
}

void UNLProjectileTask_Move::ExecuteTask(UNLPJTAbilityContext* InAbilityContext)
{
}

void UNLProjectileTask_Move::EndTask(UNLPJTAbilityContext* InAbilityContext)
{
    Super::EndTask(InAbilityContext);

    if (InAbilityContext == nullptr)
    {
        return;
    }

    AActor* Owner = InAbilityContext->Owner.Get();
    if (Owner == nullptr || Owner->IsValidLowLevel() == false)
    {
        return;
    }
}
