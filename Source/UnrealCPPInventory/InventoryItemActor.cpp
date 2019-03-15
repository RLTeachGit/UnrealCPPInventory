// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItemActor.h"

//Needed for Static Mesh
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include <EngineGlobals.h> //Needed for GEngine->AddOnScreenDebugMessage()
#include <Runtime/Engine/Classes/Engine/Engine.h> //Needed for GEngine->AddOnScreenDebugMessage()

#define DebugPrint(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)
#define ErrorPrint(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text)


// Sets default values
AInventoryItemActor::AInventoryItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void AInventoryItemActor::BeginPlay()
{
	Super::BeginPlay();
    UPrimitiveComponent* tPrimitiveComponent = FindComponentByClass<UPrimitiveComponent>();
    if(IsValid(tPrimitiveComponent))
    {
        tPrimitiveComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
        DebugPrint("Set Collision");
    }
    else
    {
        ErrorPrint("Unable to set Collision");
    }

}

// Called every frame
void AInventoryItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

