// Fill out your copyright notice in the Description page of Project Settings.

#include "FlameBeast.h"

#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

#include "FireBall.h"

AFlameBeast::AFlameBeast()
{
	MeleeHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MeleeHitBox"));
	MeleeHitBox->SetupAttachment(GetMesh(), TEXT("FlameChargeSocket"));

	FireBallLauchPoint = CreateDefaultSubobject<USceneComponent>(TEXT("FireBallLauchPoint"));
	FireBallLauchPoint->SetupAttachment(GetMesh(), TEXT("FlameChargeSocket"));
}

void AFlameBeast::BeginPlay()
{
	Super::BeginPlay();

	MeleeHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AFlameBeast::LaunchFireBallToLocation(FVector TargetLocation)
{
	FActorSpawnParameters spawnParam;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawn the fireball
	AFireBall* fireball;
	fireball = GetWorld()->SpawnActor<AFireBall>(FireBallClass, FireBallLauchPoint->GetComponentTransform(), spawnParam);

	// Check if the fire ball that we just spawn still valid
	if (fireball->IsValidLowLevel())
	{
		FVector fireballVeloResult;
		UGameplayStatics::SuggestProjectileVelocity_CustomArc(
			this, fireballVeloResult, fireball->GetActorLocation(), TargetLocation, GetWorld()->GetGravityZ() * 3.0f, 0.6f);

		fireball->GetSphere()->AddImpulse(fireballVeloResult, NAME_None, true);
	}
}

void AFlameBeast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
