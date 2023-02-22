// Fill out your copyright notice in the Description page of Project Settings.


#include "NLActorState_Move.h"

UNLActorState_Base* UNLActorState_Move::MakeState(ANLGameCharacter* InOwnerCharacter)
{
    UNLActorState_Base* NewState = NewObject<UNLActorState_Move>();
    if (NewState != nullptr)
    {
        NewState->Init(InOwnerCharacter);
    }

    return NewState;
}

void UNLActorState_Move::OnEnter(UNLActorStateContext* InContext)
{

}

void UNLActorState_Move::OnUpdate(UNLActorStateContext* InContext, float DeltaTime)
{
}

void UNLActorState_Move::OnExit(UNLActorStateContext* InContext)
{
}
