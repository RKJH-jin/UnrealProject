// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Character/CharacterStance/NLCharacterStance.h"
#include "Character/NLEnableAction.h"

#include "NLGameCharacter.generated.h"

class ANLProjectile;
class UNLProjectileComponent;
class UNLFSMComponent;
class UNLActorStateContext;
class UNLProjectileAbility;

UCLASS(config=Game)
class ANLGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANLGameCharacter();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	virtual void Init();

#pragma region Move
	/*
		임시. 바꿔야함
	*/
	/** Called for forwards/backward input */
	virtual void MoveForward(float Value);

	/** Called for side to side input */
	virtual void MoveRight(float Value);

	virtual void Running();
	virtual void StopRunning();

	virtual void OnJumped_Implementation() override;
	virtual void Landed(const FHitResult& Hit) override;

	void ChangeWalkStance(EWalkStance InWalkStance);
	void ChangeAirStance(EAirStance InAirStance);
#pragma endregion
public:
	virtual void CreateProjectile(FVector& InAimDirection);


protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<ANLProjectile> __Projectile;

	UPROPERTY()
		UNLProjectileComponent* __ProjectileComponent;

	UPROPERTY()
		UNLFSMComponent* __FSMComponent;

	UPROPERTY()
		UNLActorStateContext* __ActorStateContext;

	UPROPERTY(BlueprintReadOnly)
		FNLCharacterStance __CharacterStance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float __MaxWalkSpeed = 1000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float __MaxRunSpeed = 1500.f;

	UPROPERTY(BlueprintReadOnly)
		bool __IsInputNow = false;

	UPROPERTY(BlueprintReadOnly)
		bool __OnGrounded = true;

	UPROPERTY()
		FNLEnableAction __EnableAction;
};

