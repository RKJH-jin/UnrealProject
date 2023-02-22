// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Projectile/ProjectileDefine.h"
#include "NLProjectileInterface.generated.h"

UINTERFACE(MinimalAPI)
class UNLProjectileInterface : public UInterface
{
	GENERATED_BODY()
};


class TOOLPROJECT_API INLProjectileInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void StartMoveTask(EPJT_MoveType InMoveType, float InSpeed, float InGravityScale = 1.0f);
};