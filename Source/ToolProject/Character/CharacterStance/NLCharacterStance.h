// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NLBattleDefine.h"

#include "NLCharacterStance.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct TOOLPROJECT_API FNLCharacterStance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EWalkStance WalkStance = EWalkStance::Walk;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EAirStance AirStance = EAirStance::Ground;
};
