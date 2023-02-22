// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NLActorState_Base.generated.h"

/**
 * 
 */

class UNLActorStateContext;
class ANLGameCharacter;

UCLASS(Abstract)
class TOOLPROJECT_API UNLActorState_Base : public UObject
{
	GENERATED_BODY()

public:
	void Init(ANLGameCharacter* InOwnerCharacter);
public:
	virtual void OnEnter(UNLActorStateContext* InContext) {};
	virtual void OnUpdate(UNLActorStateContext* InContext, float DeltaTime) {};
	virtual void OnExit(UNLActorStateContext* InContext) {};

protected:
	UPROPERTY()
		TWeakObjectPtr<ANLGameCharacter> __OwnerCharacter;
};
