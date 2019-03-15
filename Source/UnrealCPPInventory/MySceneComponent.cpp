// Fill out your copyright notice in the Description page of Project Settings.

#include "MySceneComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include <EngineGlobals.h> //Needed for GEngine->AddOnScreenDebugMessage()
#include <Runtime/Engine/Classes/Engine/Engine.h> //Needed for GEngine->AddOnScreenDebugMessage()

#define DebugPrint(text) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text); UE_LOG(LogTemp,Log,TEXT(text))}
#define ErrorPrint(text) if (GEngine) {GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text); UE_LOG(LogTemp,Error,TEXT(text))}


// Sets default values for this component's properties
UMySceneComponent::UMySceneComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
    PickupMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this,TEXT("PickupMeshComponent"));
    //PickupMeshComponent->RegisterComponent();
    PickupMeshComponent->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform); //Set Parent to us
    //PickupMeshComponent->SetupAttachment();
/*
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Geometry/Meshes/1M_Cube"));
    if (SphereVisualAsset.Succeeded())
    {
        PickupMeshComponent->SetStaticMesh(SphereVisualAsset.Object);
        PickupMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        PickupMeshComponent->SetWorldScale3D(FVector(1.0f));
    }
 */
    PickupMeshComponent->SetStaticMesh(PickupMesh);
    DebugPrint("UMySceneComponent()");
}

void UMySceneComponent::PostInitProperties()
{
    DebugPrint("PostInitProperties()");
    if( PickupMeshComponent != nullptr )
    {
        PickupMeshComponent->SetStaticMesh(PickupMesh);
        DebugPrint("SetStaticMesh()");
    }
    Super::PostInitProperties(); //Must call parent version or Kaboom
}

#if WITH_EDITOR

void UMySceneComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    DebugPrint("PostEditChangeProperty()");
    FName PropertyName = (PropertyChangedEvent.Property != nullptr)
    ? PropertyChangedEvent.Property->GetFName() : NAME_None;
    
    if( PropertyName == GET_MEMBER_NAME_CHECKED(UMySceneComponent, PickupMesh) )
    {
        if( PickupMeshComponent != nullptr )
        {
            PickupMeshComponent->SetStaticMesh(PickupMesh);
            DebugPrint("SetStaticMesh()");
        }
    }
    
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

// Called when the game starts
void UMySceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMySceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

