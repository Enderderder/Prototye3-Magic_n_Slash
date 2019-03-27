// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BurnableGrassPatch.generated.h"

UCLASS()
class MAGIC_N_SLASH_API ABurnableGrassPatch : public AActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInstancedStaticMeshComponent* LotsOfGrassComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* CylinderCollider;

public:	
	// Sets default values for this actor's properties
	ABurnableGrassPatch();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	int32 TotalSpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float SpawnRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float SpawnRadiusDistribution;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float MinHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float MaxHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float MinThickness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Procedural Generation")
	float MaxThickness;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to refresh the grass spawn
	UFUNCTION(BlueprintCallable)
	void GrassConstruction();

	// Called to get a random point in radius with distribution
	FVector GetRandomPointInRadiusDistributed(float _range, float _distribution);

	// Called to get a random size of the grass
	FVector GetRandomSize(float _minHeight, float _maxHeight, float _minThickness, float _maxThickness);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
