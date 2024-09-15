#pragma once

// Defaults
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CPP_KitchenKnife.generated.h"

UCLASS()
class PROJECTA24_API ACPP_KitchenKnife : public AActor
{
	GENERATED_BODY()

public:
	ACPP_KitchenKnife();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Knife Components")
	class UStaticMeshComponent *knifeStaticMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Knife Components")
	class UBoxComponent *boxComponent;
};
