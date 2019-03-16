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
	// Sets default values for this actor's properties
	APickupActor(const FObjectInitializer& ObjectInitializer);
	virtual void PostInitProperties() override;

	//Only relevant in Editor
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void	UpdateMesh();

	UFUNCTION()
	void	OnOverlap(AActor * MyActor, AActor * OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY()
	UStaticMeshComponent* PickupMeshComponent;

	UPROPERTY(EditAnywhere, Category = "User")
	UStaticMesh* PickupMesh;

};
