// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NLBattleDefine.h"

#include "NLActorStateFactory.generated.h"

/**
 * 
 */

class ANLGameCharacter;
class UNLActorState_Base;

UCLASS()
class TOOLPROJECT_API UNLActorStateFactory : public UObject
{
	GENERATED_BODY()

public:
	static void MakeStateList(ANLGameCharacter* InOwnerCharacter, TMap<EActorStateType, UNLActorState_Base*>& OutList);

};
