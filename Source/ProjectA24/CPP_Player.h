#pragma once

// Custom includes
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Defaults
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Player.generated.h"

UCLASS()
class PROJECTA24_API ACPP_Player : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_Player();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
	// Variables
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
		class UInputMappingContext *playerIMC;
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
		class UInputAction *jumpAction;
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
		class UInputAction *moveAction;

	// Functions
	UFUNCTION(Category = "Player Movement")
		void PlayerMovement(const FInputActionValue &Value);
};