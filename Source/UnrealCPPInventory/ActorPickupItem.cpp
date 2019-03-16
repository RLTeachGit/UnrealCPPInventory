// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPickupItem.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include <EngineGlobals.h> //Needed for GEngine->AddOnScreenDebugMessage()
#include <Runtime/Engine/Classes/Engine/Engine.h> //Needed for GEngine->AddOnScreenDebugMessage()

#define DebugPrint(text) if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text); UE_LOG(LogTemp,Log,TEXT(text))}
#define ErrorPrint(text) if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text); UE_LOG(LogTemp,Error,TEXT(text))}


// Sets default values for this component's properties
UActorPickupItem::UActorPickupItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UActorPickupItem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActorPickupItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

