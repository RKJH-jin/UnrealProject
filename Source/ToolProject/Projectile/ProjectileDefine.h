// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(Blueprintable)
enum class EPJT_MoveType : uint8
{
    Stop,
    Straight,
    Arc,

};

UENUM(Blueprintable)
enum class EPJT_CollisionType : uint8
{
    None,
    Sphere,
    Capsule,
    Rect,
};