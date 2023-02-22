// Fill out your copyright notice in the Description page of Project Settings.


#include "NLProjectileMovementComponent.h"
#include "NLProjectileTask_Move.h"

#include "Kismet/GameplayStatics.h"

void UNLProjectileMovementComponent::SetMovement(EPJT_MoveType InMoveType, float InSpeed, float InGravityScale)
{
    // 초기화
    Velocity = FVector::ZeroVector;
    ProjectileGravityScale = 1.f;

    // TODO :: 타입 생길 때 마다 추가
    switch (InMoveType)
    {
        case EPJT_MoveType::Stop:
        {
            Velocity = FVector::ZeroVector;
            ProjectileGravityScale = 0.f;
            break;
        }

        case EPJT_MoveType::Straight:
        {
            if (GetOwner() != nullptr && GetOwner()->IsValidLowLevel())
            {
                Velocity = InSpeed * GetOwner()->GetActorForwardVector();
            }

            ProjectileGravityScale = 0.f;
            
            break;
        }

        case EPJT_MoveType::Arc:
        {
            Velocity = InSpeed * GetOwner()->GetActorForwardVector();
            
            ProjectileGravityScale = InGravityScale;

            //UGameplayStatics::SuggestProjectileVelocity_CustomArc(GetOwner(), Velocity, GetOwner()->GetActorLocation(), FVector EndPos, float OverrideGravityZ /*= 0*/, float ArcParam /*= 0.5f */);
            break;
        }
    }
    
}