// Fill out your copyright notice in the Description page of Project Settings.

#include "BurnableGrassPatch.h"

#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
ABurnableGrassPatch::ABurnableGrassPatch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	LotsOfGrassComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("LotsOfGrass"));
	RootComponent = LotsOfGrassComponent;

	CylinderCollider = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CylinderCollider"));
	CylinderCollider->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABurnableGrassPatch::BeginPlay()
{
	Super::BeginPlay();

	// CONSTRUCTTTTTTTTTTTTTT!!!!!!!!!
	GrassConstruction();
}

void ABurnableGrassPatch::GrassConstruction()
{
	FVector spawnLocation;
	FVector spawnScale;
	FTransform spawnTransform;

	LotsOfGrassComponent->ClearInstances();
	for (int32 i = 0; i < TotalSpawnCount; ++i)
	{
		spawnLocation = GetRandomPointInRadiusDistributed(SpawnRadius, SpawnRadiusDistribution);
		spawnScale = GetRandomSize(MinHeight, MaxHeight, MinThickness, MaxThickness);
		float randomRotationZ = FMath::FRandRange(0.0f, 360.0f);

		spawnTransform.SetLocation(spawnLocation);
		spawnTransform.SetScale3D(spawnScale);
		spawnTransform.SetRotation(FQuat(FVector(0.0f, 0.0f, 1.0f), randomRotationZ));
		
		LotsOfGrassComponent->AddInstance(spawnTransform);
	}
}

FVector ABurnableGrassPatch::GetRandomPointInRadiusDistributed(float _range, float _distribution)
{
	FVector resultVec;

	float angle = FMath::FRandRange(0.0f, 360.0f);
	float distribute = FMath::FRandRange(-_distribution, _distribution);
	float distance = FMath::FRandRange(0.0f, _range + distribute);
	float offsetX = distance * FMath::Cos(angle);
	float offsetY = distance * FMath::Sin(angle);

	resultVec = FVector(offsetX, offsetY, 0.0f);

	return resultVec;
}

FVector ABurnableGrassPatch::GetRandomSize(float _minHeight, float _maxHeight, float _minThickness, float _maxThickness)
{
	FVector resultVec;

	float thickness = FMath::FRandRange(_minThickness, _maxThickness);
	float height = FMath::FRandRange(_minHeight, _maxHeight);

	resultVec = FVector(thickness, thickness, height);

	return resultVec;
}

// Called every frame
void ABurnableGrassPatch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

