// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "NLProjectileTask.h"
#include "NLProjectileTask_Move.generated.h"

/**
 * 
 */
UCLASS()
class TOOLPROJECT_API UNLProjectileTask_Move : public UNLProjectileTask
{
	GENERATED_BODY()
public:
	virtual void StartTask(UNLPJTAbilityContext* InAbilityContext) override;
	virtual void ExecuteTask(UNLPJTAbilityContext* InAbilityContext) override;
	virtual void EndTask(UNLPJTAbilityContext* InAbilityContext) override;
public:
	UPROPERTY(EditAnywhere, Category = "Projectile", DisplayName = "MoveType")
		EPJT_MoveType __MoveType;

	UPROPERTY(EditAnywhere, Category = "Projectile", DisplayName = "Speed")
		float __Speed = 0.f;

	UPROPERTY(EditAnywhere, Category = "Projectile", DisplayName = "Gravity")
		float __GravityScale = 980.f;
};
