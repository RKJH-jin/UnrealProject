// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ProjectileDefine.h"
#include "NLProjectileMovementComponent.generated.h"

/**
 * 
 */

class UNLProjectileTask_Move;

UCLASS()
class TOOLPROJECT_API UNLProjectileMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()
	
public:
	void SetMovement(EPJT_MoveType InMoveType, float InSpeed, float InGravityScale);
};
