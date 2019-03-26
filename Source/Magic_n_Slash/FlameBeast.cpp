// Fill out your copyright notice in the Description page of Project Settings.

#include "FlameBeast.h"

#include "Components/SceneCaptureComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

#include "FireBall.h"

AFlameBeast::AFlameBeast()
{
	FireBallLauchPoint = CreateDefaultSubobject<USceneComponent>(TEXT("FireBallLauchPoint"));
	FireBallLauchPoint->SetupAttachment(GetMesh());
}

void AFlameBeast::BeginPlay()
{
	Super::BeginPlay();
}

void AFlameBeast::LaunchFireBallToLocation(FVector TargetLocation)
{
	FActorSpawnParameters spawnParam;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	// Spawn the fireball
	AFireBall* fireball;
	fireball = GetWorld()->SpawnActor<AFireBall>(FireBallClass, FireBallLauchPoint->GetComponentTransform(), spawnParam);

	FVector fireballVeloResult;
	UGameplayStatics::SuggestProjectileVelocity_CustomArc(
		this, fireballVeloResult, fireball->GetActorLocation(), TargetLocation, 0.0f, 0.6f);

	fireball->GetSphere()->AddImpulse(fireballVeloResult, NAME_None, true);
}

void AFlameBeast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
