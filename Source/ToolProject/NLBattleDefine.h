// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(Blueprintable)
enum class EActorStateType : uint8
{
    Move,
    Attack,
    Death,
};

UENUM(Blueprintable)
enum class EWalkStance : uint8
{
    Walk,
    Run,
    Jump,
};

UENUM(Blueprintable)
enum class EAirStance : uint8
{
    Ground,
    Air,
};