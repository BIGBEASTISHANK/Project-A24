
#include "CPP_Player.h"

ACPP_Player::ACPP_Player()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Player::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// getting the playerController
	auto playerController = Cast<APlayerController>(GetController());

	// getting the local player enhanced input subsystem
	auto enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
	// adding the input mapping context
	enhancedInputSubsystem->AddMappingContext(playerIMC, 0);

	// getting the enhanced input component
	auto playerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	// Movement actions binding to functions
	playerEnhancedInputComponent->BindAction(jumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	playerEnhancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &ACPP_Player::PlayerMovement);
}

// CustomFunctions
void ACPP_Player::PlayerMovement(const FInputActionValue &Value)
{
	// Setting variables
	FVector2D moveInput = Value.Get<FVector2D>();
	moveInput.Normalize();
	FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

	// Moving player
	if (moveInput.X != 0.f)
	{
		FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(Direction, moveInput.X);
	}

	if (moveInput.Y != 0.f)
	{
		FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(Direction, moveInput.Y);
	}
}