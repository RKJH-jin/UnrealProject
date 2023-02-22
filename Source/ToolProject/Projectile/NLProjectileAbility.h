// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NLProjectileAbility.generated.h"

/**
 * 
 */

class UNLProjectileTask;

UCLASS(Blueprintable)
class TOOLPROJECT_API UNLProjectileAbility : public UObject
{
	GENERATED_BODY()

public:
	const float GetTimeLength() { return __TimeLength; }
	const TArray<UNLProjectileTask*>& GetTaskList() { return __AllTaskList; }
public:
	void UpdateAbility(float DeltaTime);
	void EndAbility();

protected:
	UPROPERTY(Instanced, BlueprintReadWrite, EditAnywhere)
		TArray<UNLProjectileTask*> __AllTaskList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float __TimeLength = 0.f;
};
