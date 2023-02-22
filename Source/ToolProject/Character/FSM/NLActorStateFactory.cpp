// Fill out your copyright notice in the Description page of Project Settings.


#include "NLActorStateFactory.h"
#include "NLActorState_Base.h"
#include "NLActorState_Move.h"
#include "NLActorState_Attack.h"
#include "NLActorState_Death.h"

#include "Character/NLGameCharacter.h"


void UNLActorStateFactory::MakeStateList(ANLGameCharacter* InOwnerCharacter, TMap<EActorStateType, UNLActorState_Base*>& OutList)
{
    if (InOwnerCharacter == nullptr || InOwnerCharacter->IsValidLowLevel() == false)
    {
        return;
    }

    OutList.Empty(3);
    OutList.Emplace(EActorStateType::Move, UNLActorState_Move::MakeState(InOwnerCharacter));
    OutList.Emplace(EActorStateType::Attack, UNLActorState_Attack::MakeState(InOwnerCharacter));
    OutList.Emplace(EActorStateType::Death, UNLActorState_Death::MakeState(InOwnerCharacter));
}
