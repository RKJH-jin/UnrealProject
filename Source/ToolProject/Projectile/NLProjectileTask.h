// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "ProjectileDefine.h"
#include "NLProjectileTask.generated.h"

/**
 * 
 */
class UNLPJTAbilityContext;

UCLASS(Abstract, BlueprintType, EditInlineNew)
class TOOLPROJECT_API UNLProjectileTask : public UObject
{
	GENERATED_BODY()
	
public:
	virtual bool CanStart(float CurrentTime);
	virtual bool CanEnd(float CurrentTime);

	virtual void StartTask(UNLPJTAbilityContext* InAbilityContext);
	virtual void ExecuteTask(UNLPJTAbilityContext* InAbilityContext);
	virtual void EndTask(UNLPJTAbilityContext* InAbilityContext);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float __StartTime = 0.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float __EndTime = 0.f;
};
