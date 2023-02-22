// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NLActorState_Base.h"
#include "NLActorState_Attack.generated.h"

/**
 * 
 */

class UNLActorStateContext;
class ANLGameCharacter;

UCLASS()
class TOOLPROJECT_API UNLActorState_Attack : public UNLActorState_Base
{
	GENERATED_BODY()
public:
	static UNLActorState_Base* MakeState(ANLGameCharacter* InOwnerCharacter);

public:
	virtual void OnEnter(UNLActorStateContext* InContext) override;
	virtual void OnUpdate(UNLActorStateContext* InContext, float DeltaTime) override;
	virtual void OnExit(UNLActorStateContext* InContext) override;

protected:

};
