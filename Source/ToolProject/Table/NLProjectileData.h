// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "NLProjectileData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNLProjectileData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float LifeTime = 0.f;


};
