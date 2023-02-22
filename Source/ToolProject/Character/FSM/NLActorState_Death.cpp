// Fill out your copyright notice in the Description page of Project Settings.


#include "NLActorState_Death.h"

UNLActorState_Base* UNLActorState_Death::MakeState(ANLGameCharacter* InOwnerCharacter)
{
    UNLActorState_Base* NewState = NewObject<UNLActorState_Death>();
    if (NewState != nullptr)
    {
        NewState->Init(InOwnerCharacter);
    }

    return NewState;
}

void UNLActorState_Death::OnEnter(UNLActorStateContext* InContext)
{
}

void UNLActorState_Death::OnUpdate(UNLActorStateContext* InContext, float DeltaTime)
{
}

void UNLActorState_Death::OnExit(UNLActorStateContext* InContext)
{
}
