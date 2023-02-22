// Fill out your copyright notice in the Description page of Project Settings.


#include "NLActorState_Attack.h"

UNLActorState_Base* UNLActorState_Attack::MakeState(ANLGameCharacter* InOwnerCharacter)
{
    UNLActorState_Base* NewState = NewObject<UNLActorState_Attack>();
    if (NewState != nullptr)
    {
        NewState->Init(InOwnerCharacter);
    }
    
    return NewState;
}

void UNLActorState_Attack::OnEnter(UNLActorStateContext* InContext)
{

}

void UNLActorState_Attack::OnUpdate(UNLActorStateContext* InContext, float DeltaTime)
{
}

void UNLActorState_Attack::OnExit(UNLActorStateContext* InContext)
{
}
