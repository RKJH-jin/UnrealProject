// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Component/NLProjectileComponent.h"
#include "Projectile/NLProjectile.h"
#include "Projectile/NLProjectileInstance.h"
#include "Projectile/NLProjectileAbility.h"

// Sets default values for this component's properties
UNLProjectileComponent::UNLProjectileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNLProjectileComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNLProjectileComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNLProjectileComponent::CreateProjectile(TSubclassOf<ANLProjectile> InProjectile, FVector& InAimDirection)
{
	if (InProjectile == nullptr)
	{
		return;
	}

	FTransform SpawnTransform = GetOwner()->GetTransform();
	if (InAimDirection.IsNearlyZero() == false)
	{
		SpawnTransform.SetRotation(InAimDirection.Rotation().Quaternion());
	}
	FActorSpawnParameters NewParam;
	ANLProjectile* NewProjectile = GetWorld()->SpawnActor<ANLProjectile>(InProjectile, SpawnTransform, NewParam);
	if (NewProjectile == nullptr || NewProjectile->IsValidLowLevel() == false)
	{
		return;
	}

	NewProjectile->Init();

	__ProjectileList.Emplace(NewProjectile);
}