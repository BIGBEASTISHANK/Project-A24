#include "CPP_Player.h"

//
ACPP_Player::ACPP_Player()
{
  PrimaryActorTick.bCanEverTick = true;

  // Setting playerCamera
  playerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
  playerCamera->SetupAttachment(RootComponent);
  playerCamera->bUsePawnControlRotation = true;
  playerCamera->FieldOfView = playerFOV;
}

//
void ACPP_Player::BeginPlay()
{
  Super::BeginPlay();

  // Setting Movement Component
  MovementComponent = GetCharacterMovement();
  defaultMaxWalkSpeed = MovementComponent->GetMaxSpeed();
}

//
void ACPP_Player::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}

//
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

  // Movement actions binding
  playerEnhancedInputComponent->BindAction(jumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
  playerEnhancedInputComponent->BindAction(moveAction, ETriggerEvent::Triggered, this, &ACPP_Player::PlayerMovement);
  playerEnhancedInputComponent->BindAction(lookAction, ETriggerEvent::Triggered, this, &ACPP_Player::CameraMovement);
  playerEnhancedInputComponent->BindAction(sprintAction, ETriggerEvent::Started, this, &ACPP_Player::PlayerSprintStarted);
  playerEnhancedInputComponent->BindAction(sprintAction, ETriggerEvent::Completed, this, &ACPP_Player::PlayerSprintStopped);

  // Intract Action binding
  playerEnhancedInputComponent->BindAction(pickDropAction, ETriggerEvent::Triggered, this, &ACPP_Player::PickDrop);
}

// CustomFunctions
// Player movement
void ACPP_Player::PlayerMovement(const FInputActionValue &Value)
{
  FVector2D moveInput = Value.Get<FVector2D>();
  moveInput.Normalize();

  // Movement front-back
  AddMovementInput(GetActorForwardVector(), moveInput.X);
  // Movement left-right
  AddMovementInput(GetActorRightVector(), moveInput.Y);
}

// Camera movement
void ACPP_Player::CameraMovement(const FInputActionValue &Value)
{
  FVector2D camInput = Value.Get<FVector2D>();

  // Fixing camera sensitivity value between 0 and 1
  cameraSensitivity = FMath::Clamp(cameraSensitivity, 0.0f, 1.0f);

  // Look left right
  AddControllerYawInput(camInput.X * cameraSensitivity);
  // Look up down
  AddControllerPitchInput(camInput.Y * cameraSensitivity);
}

// Player Sprinting
void ACPP_Player::PlayerSprintStarted(const FInputActionValue &Value)
{
  // Start sprinting
  MovementComponent->MaxWalkSpeed = playerSpringSpeed;
}
void ACPP_Player::PlayerSprintStopped(const FInputActionValue &Value)
{
  // Stop Sprinting
  MovementComponent->MaxWalkSpeed = defaultMaxWalkSpeed;
} 

// Pickup and drop
void ACPP_Player::PickDrop(const FInputActionValue &Value)
{

}