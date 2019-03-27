// Fill out your copyright notice in the Description page of Project Settings.

#include "BurnableGrassPatch.h"

#include "Components/InstancedStaticMeshComponent.h"

// Sets default values
ABurnableGrassPatch::ABurnableGrassPatch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LotsOfGrassComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("LotsOfGrass"));
	RootComponent = LotsOfGrassComponent;

}

// Called when the game starts or when spawned
void ABurnableGrassPatch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABurnableGrassPatch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

