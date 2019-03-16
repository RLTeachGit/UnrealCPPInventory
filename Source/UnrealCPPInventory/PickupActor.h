// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class UNREALCPPINVENTORY_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties, this is the extended version
    //Which allows access to FObjectInitializer helpr functions
    //such as CreateDefaultSubobject() which makes the MeshComponent
	APickupActor(const FObjectInitializer& ObjectInitializer);
    
    //Happens after all the initalisation but before it Begins
    //See: https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Actors/ActorLifecycle
	virtual void PostInitProperties() override;

	//Only relevant in Editor, this runs when item is changed in IDE
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    
    //Internal function which updates the Mesh being shown to one linkd in IDE
	void	UpdateMesh();

    //Callback to function dealing with Overlap
	UFUNCTION()
	void	OnOverlap(AActor * MyActor, AActor * OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Will store Mesh component allocated at runtime here
	UPROPERTY()
	UStaticMeshComponent* PickupMeshComponent;

    //Link in IDE, this is the mesh we will show for pickup
	UPROPERTY(EditAnywhere, Category = "User")
	UStaticMesh* PickupMesh;
    
    //Link in IDE, this is the mesh we will show for pickup
    UPROPERTY(EditAnywhere, Category = "User")
    TSubclassOf<UDamageType> DamageType;

};
