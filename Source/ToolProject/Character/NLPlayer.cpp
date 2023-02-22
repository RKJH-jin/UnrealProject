// Copyright Epic Games, Inc. All Rights Reserved.

#include "NLPlayer.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"

#include "Projectile/Component/NLProjectileComponent.h"

//////////////////////////////////////////////////////////////////////////
// ANLPlayer

ANLPlayer::ANLPlayer()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ANLPlayer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

//////////////////////////////////////////////////////////////////////////
// Input

void ANLPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ANLGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANLGameCharacter::MoveRight);

	//// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	//// "turn" handles devices that provide an absolute delta, such as a mouse.
	//// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ANLPlayer::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANLPlayer::LookUpAtRate);

	//// handle touch devices
	//PlayerInputComponent->BindTouch(IE_Pressed, this, &ANLPlayer::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &ANLPlayer::TouchStopped);


	// Add Input Action
	PlayerInputComponent->BindAction("LeftButton", IE_Pressed, this, &ANLPlayer::MouseLeftButton);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ANLGameCharacter::Running);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ANLGameCharacter::StopRunning);
}

void ANLPlayer::CreateProjectile(FVector& InAimDirection)
{
	if (__ProjectileComponent == nullptr || __ProjectileComponent->IsValidLowLevel() == false)
	{
		return;
	}

	__ProjectileComponent->CreateProjectile(__Projectile, InAimDirection);
}

void ANLPlayer::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ANLPlayer::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ANLPlayer::MouseLeftButton()
{
	FVector AimLocation = FVector::ZeroVector;
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController == nullptr)
	{
		return;
	}

	int32 ViewportSizeX;
	int32 ViewportSizeY;

	PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector WorldLocation;
	FVector WorldDirection;
	PlayerController->DeprojectScreenPositionToWorld(ViewportSizeX * 0.5f, ViewportSizeY * 0.5f, WorldLocation, WorldDirection);

	CreateProjectile(WorldDirection);
}

void ANLPlayer::MouseRightButton()
{
}

void ANLPlayer::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ANLPlayer::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}