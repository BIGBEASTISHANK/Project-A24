#include "CPP_KitchenKnife.h"

//
ACPP_KitchenKnife::ACPP_KitchenKnife()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Setting knifeMesh
	knifeStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Knife Static Mesh"));
	knifeStaticMesh->SetupAttachment(RootComponent);

	// Setting boxComponent
	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	boxComponent->SetupAttachment(knifeStaticMesh);
}

//
void ACPP_KitchenKnife::BeginPlay()
{
	Super::BeginPlay();
}

//
void ACPP_KitchenKnife::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

