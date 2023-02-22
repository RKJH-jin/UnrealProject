// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile/NLProjectileInterface.h"
#include "Projectile/ProjectileDefine.h"
#include "NLProjectile.generated.h"


class UNLProjectileMovementComponent;
class UNLProjectileInstance;
class USphereComponent;
class UNLProjectileAbility;

UCLASS()
class TOOLPROJECT_API ANLProjectile : public AActor, public INLProjectileInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANLProjectile();

public:
	void Init();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Release();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Interface Function
	virtual void StartMoveTask_Implementation(EPJT_MoveType InMoveType, float InSpeed, float InGravityScale = 1.0f) override;
protected:
	UPROPERTY()
		UNLProjectileMovementComponent* __MovementComp;

	UPROPERTY()
		USphereComponent* __SphereComponent;

	UPROPERTY()
		UNLProjectileInstance* __Instance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<UNLProjectileAbility> __Ability;
		
};