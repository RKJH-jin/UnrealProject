// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NLPJTAbilityContext.generated.h"

/**
 * 
 */
class UNLProjectileAbility;

UCLASS()
class TOOLPROJECT_API UNLPJTAbilityContext : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
		TWeakObjectPtr<UNLProjectileAbility> Ability;

	UPROPERTY()
		float CurrentTime = 0.f;

	UPROPERTY()
		TWeakObjectPtr<AActor> Owner;

};
