// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "ProjectileDefine.h"
#include "NLProjectileInstance.generated.h"

/**
 * 
 */

class UNLProjectileAbility;
class UNLProjectileTask;
class UNLPJTAbilityContext;

UCLASS(Blueprintable)
class TOOLPROJECT_API UNLProjectileInstance : public UObject
{
	GENERATED_BODY()

public:
	void OnStart(AActor* InOwner, TSubclassOf<UNLProjectileAbility> InAbility);
	void OnUpdate(float DeltaTime);
	void OnEnd();
public:
	UPROPERTY()
		UNLProjectileAbility* __Ability;

	UPROPERTY()
		TArray<UNLProjectileTask*> __AllTaskList;

	UPROPERTY()
		TArray<UNLProjectileTask*> __ActiveTaskList;

	UPROPERTY()
		UNLPJTAbilityContext* __AbilityContext;


	float __CurrentTime = 0.f;
};
