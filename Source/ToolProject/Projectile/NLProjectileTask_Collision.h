// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "NLProjectileTask.h"
#include "NLProjectileTask_Collision.generated.h"

/**
 * 
 */
UCLASS()
class TOOLPROJECT_API UNLProjectileTask_Collision : public UNLProjectileTask
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Projectile", DisplayName = "Collision Shape")
		EPJT_CollisionType __CollisionType;

};
