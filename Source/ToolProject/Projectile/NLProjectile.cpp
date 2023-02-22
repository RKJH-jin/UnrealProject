// Fill out your copyright notice in the Description page of Project Settings.


#include "NLProjectile.h"

#include "NLProjectileInstance.h"
#include "NLProjectileAbility.h"
#include "NLProjectileTask.h"
#include "NLProjectileTask_Move.h"
#include "NLProjectileTask_Collision.h"
#include "NLProjectileMovementComponent.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ANLProjectile::ANLProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	__MovementComp = CreateDefaultSubobject<UNLProjectileMovementComponent>(TEXT("ProjectileMovement"));
	
	__SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	__SphereComponent->SetSphereRadius(100.f);
}

void ANLProjectile::Init()
{
	if (__Ability == nullptr)
	{
		Release();
		return;
	}

	__Instance = NewObject<UNLProjectileInstance>(this);
	if (__Instance == nullptr || __Instance->IsValidLowLevel() == false)
	{
		Release();
		return;
	}

	__Instance->OnStart(this, __Ability);
}

// Called when the game starts or when spawned
void ANLProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANLProjectile::Release()
{
	Destroy();
}

// Called every frame
void ANLProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (__Instance != nullptr)
	{
		__Instance->OnUpdate(DeltaTime);
	}
}

void ANLProjectile::StartMoveTask_Implementation(EPJT_MoveType InMoveType, float InSpeed, float InGravityScale)
{
	__MovementComp->SetMovement(InMoveType, InSpeed, InGravityScale);
}
