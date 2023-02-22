// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NLBattleDefine.h"

#include "NLFSMComponent.generated.h"

class UNLActorState_Base;
class UNLActorStateContext;

/*
	TickComponent 돌리는 대신 Character에서 Tick 돌릴꺼
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOOLPROJECT_API UNLFSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNLFSMComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void Init();
public:
	/*
		Event Function
	*/

public:
	void OnEnter(UNLActorStateContext* InContext);
	void OnUpdate(UNLActorStateContext* InContext, float DeltaTime);
	void OnExit(UNLActorStateContext* InContext);

protected:

protected:
	UPROPERTY()
		TMap<EActorStateType, UNLActorState_Base*> __ActorStateList;

	UPROPERTY()
		UNLActorState_Base* __CurrentActorState;
};
