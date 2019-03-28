// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleCheckPoint.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASimpleCheckPoint::ASimpleCheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	EditorOnlyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EditorOnlyMesh"));
	EditorOnlyMesh->SetupAttachment(RootComponent);

	CheckPointPlayerRespawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("CheckPointPlayerRespawnLocation"));
	CheckPointPlayerRespawnLocation->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASimpleCheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleCheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform ASimpleCheckPoint::GetRespawnTransform() const
{
	return CheckPointPlayerRespawnLocation->GetComponentTransform();
}

