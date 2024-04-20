#pragma once

// Custom includes
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
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
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
		class UInputAction *lookAction;
	
	UPROPERTY(EditAnywhere, Category = "Player Values", meta = (UIMin = "0.1", UIMax = "1.0"))
		float cameraSensitivity = 0.45f;
	UPROPERTY(EditAnywhere, Category = "Player Values", meta = (UIMin = "30", UIMax = "120"))
		int playerFOV = 90;
	
	UPROPERTY(EditAnywhere, Category = "Player Components")
		class UCameraComponent *playerCamera;

	// Functions
	void PlayerMovement(const FInputActionValue &Value);
	void CameraMovement(const FInputActionValue &Value);
};
