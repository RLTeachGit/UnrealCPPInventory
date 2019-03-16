// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupActor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include <EngineGlobals.h> //Needed for GEngine->AddOnScreenDebugMessage()
#include <Runtime/Engine/Classes/Engine/Engine.h> //Needed for GEngine->AddOnScreenDebugMessage()
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

#define DebugPrint(text) {if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text); UE_LOG(LogTemp,Log,TEXT(text))}}
#define ErrorPrint(text) {if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text); UE_LOG(LogTemp,Error,TEXT(text))}}


// Sets default values
APickupActor::APickupActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMeshComponent"));

	RootComponent = PickupMeshComponent;

	PickupMeshComponent->SetSimulatePhysics(false);

	UpdateMesh();
}

void APickupActor::PostInitProperties() 
{
	Super::PostInitProperties(); //Must call parent version or Kaboom
	UpdateMesh();
}





//Only relevant in Editor
#if WITH_EDITOR

void APickupActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	DebugPrint("PostEditChangeProperty()");
	FName PropertyName = (PropertyChangedEvent.Property != nullptr)	? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(APickupActor, PickupMesh))
	{
		UpdateMesh();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif


// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APickupActor::OnOverlap); //Link Overlap action handler to our code
	
}


void APickupActor::OnOverlap(AActor * MyActor, AActor * OtherActor)
{
	if(GEngine != nullptr) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, FString::Printf(TEXT("OnOverlap() with %s"), *OtherActor->GetName()));
}


void APickupActor::UpdateMesh()
{
	if (PickupMeshComponent != nullptr)
	{
		PickupMeshComponent->SetStaticMesh(PickupMesh);
		PickupMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap); //Make it non blocking
		DebugPrint("SetStaticMesh()");
	}
	else
	{
		ErrorPrint("SetStaticMesh() Mesh null");
	}
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

