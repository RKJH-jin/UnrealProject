// Fill out your copyright notice in the Description page of Project Settings.


#include "NLActorState_Base.h"
#include "Character/NLGameCharacter.h"

void UNLActorState_Base::Init(ANLGameCharacter* InOwnerCharacter)
{
    __OwnerCharacter = InOwnerCharacter;
}