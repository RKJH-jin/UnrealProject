// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "NLBattleDefine.h"

#include "NLEnableAction.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNLEnableAction
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool EnableToMove = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool EnableToAttack = false;

};