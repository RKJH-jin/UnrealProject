// Copyright Epic Games, Inc. All Rights Reserved.

#include "NLGameCharacter.h"
#include "Components/CapsuleComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "Projectile/Component/NLProjectileComponent.h"

#include "Character/FSM/NLFSMComponent.h"
#include "Character/FSM/NLActorStateContext.h"

#include "Kismet/GameplayStatics.h"

//////////////////////////////////////////////////////////////////////////
// ANLGameCharacter

ANLGameCharacter::ANLGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	__ProjectileComponent = CreateDefaultSubobject<UNLProjectileComponent>(TEXT("ProjectileComponent"));
	//__FSMComponent = CreateDefaultSubobject<UNLFSMComponent>(TEXT("FSMComponent"));
}

void ANLGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void ANLGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (__FSMComponent != nullptr && __FSMComponent->IsValidLowLevel())
	{
		__FSMComponent->OnUpdate(__ActorStateContext, DeltaSeconds);
	}

	
	//const UEnum* EnumWalkStance = FindObject<UEnum>(ANY_PACKAGE, TEXT("EWalkStance"), true);
	//if (EnumWalkStance)
	//{
	//	FString EnumString = EnumWalkStance->GetNameStringByValue((int64)__CharacterStance.WalkStance);
	//	UE_LOG(LogTemp, Error, TEXT("ANLGameCharacter::Tick - CharacterStance : %s"), *EnumString);
	//}
	
}

void ANLGameCharacter::Init()
{
	/*
		Character Initialize
	*/
	__ActorStateContext = NewObject<UNLActorStateContext>(this);
	if (__ActorStateContext == nullptr || __ActorStateContext->IsValidLowLevel() == false)
	{
		//Error
	}

	/*
		Component Initialize
	*/
	if (__FSMComponent != nullptr && __FSMComponent->IsValidLowLevel())
	{
		__FSMComponent->Init();
	}

	//__EnableAction.Reset();
}

#pragma region Move
void ANLGameCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ANLGameCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}

	// Forward 이후 Right가 불리므로 여기서만
	if (GetLastMovementInputVector().IsNearlyZero() == true)
	{
		__IsInputNow = false;
		ChangeWalkStance(EWalkStance::Walk);
	}
	else
	{
		__IsInputNow = true;
	}
}

void ANLGameCharacter::Running()
{
	ChangeWalkStance(EWalkStance::Run);
}

void ANLGameCharacter::StopRunning()
{
	ChangeWalkStance(EWalkStance::Walk);
}

void ANLGameCharacter::OnJumped_Implementation()
{
	Super::OnJumped_Implementation();

	ChangeAirStance(EAirStance::Air);
}

void ANLGameCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	ChangeAirStance(EAirStance::Ground);
}

void ANLGameCharacter::ChangeWalkStance(EWalkStance InWalkStance)
{
	if (__CharacterStance.WalkStance == InWalkStance)
	{
		return;
	}

	__CharacterStance.WalkStance = InWalkStance;
	
	if (__CharacterStance.WalkStance == EWalkStance::Walk)
	{
		GetCharacterMovement()->MaxWalkSpeed = __MaxWalkSpeed;
	}
	else if (__CharacterStance.WalkStance == EWalkStance::Run)
	{
		GetCharacterMovement()->MaxWalkSpeed = __MaxRunSpeed;
	}
}

void ANLGameCharacter::ChangeAirStance(EAirStance InAirStance)
{
	if (__CharacterStance.AirStance == InAirStance)
	{
		return;
	}

	__CharacterStance.AirStance = InAirStance;
}

#pragma endregion

void ANLGameCharacter::CreateProjectile(FVector& InAimDirection)
{
	if (__ProjectileComponent == nullptr || __ProjectileComponent->IsValidLowLevel() == false)
	{
		return;
	}

	__ProjectileComponent->CreateProjectile(__Projectile, InAimDirection);
}
