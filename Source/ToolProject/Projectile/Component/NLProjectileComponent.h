// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NLProjectileComponent.generated.h"

class UNLProjectileInstance;
class ANLProjectile;
class UNLProjectileAbility;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOOLPROJECT_API UNLProjectileComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNLProjectileComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CreateProjectile(TSubclassOf<ANLProjectile> InProjectile, FVector& InAimDirection);

protected:
	UPROPERTY()
		TArray<ANLProjectile*> __ProjectileList;
};
