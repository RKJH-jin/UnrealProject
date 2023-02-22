// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FSM/NLFSMComponent.h"
#include "Character/FSM/NLActorState_Base.h"
#include "Character/FSM/NLActorStateFactory.h"
#include "Character/NLGameCharacter.h"

// Sets default values for this component's properties
UNLFSMComponent::UNLFSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UNLFSMComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UNLFSMComponent::Init()
{
	UNLActorStateFactory::MakeStateList(Cast<ANLGameCharacter>(GetOwner()), __ActorStateList);

	if (__ActorStateList.Contains(EActorStateType::Move))
	{
		__CurrentActorState = __ActorStateList[EActorStateType::Move];
	}
}

void UNLFSMComponent::OnEnter(UNLActorStateContext* InContext)
{
	if (__CurrentActorState == nullptr || __CurrentActorState->IsValidLowLevel() == false)
	{
		return;
	}

	__CurrentActorState->OnEnter(InContext);
}

void UNLFSMComponent::OnUpdate(UNLActorStateContext* InContext, float DeltaTime)
{
	if (__CurrentActorState == nullptr || __CurrentActorState->IsValidLowLevel() == false)
	{
		return;
	}

	__CurrentActorState->OnUpdate(InContext, DeltaTime);
}

void UNLFSMComponent::OnExit(UNLActorStateContext* InContext)
{
	if (__CurrentActorState == nullptr || __CurrentActorState->IsValidLowLevel() == false)
	{
		return;
	}

	__CurrentActorState->OnExit(InContext);
}