// Fill out your copyright notice in the Description page of Project Settings.

#include "FlameBeast.h"


#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

#include "FireBall.h"

AFlameBeast::AFlameBeast()
{

}

void AFlameBeast::BeginPlay()
{
	Super::BeginPlay();
}

void AFlameBeast::LaunchFireBallToLocation(FVector TargetLocation)
{
	// Spawn the fireball
	AFireBall* fireball;
	fireball = GetWorld()->SpawnActor<AFireBall>(FireBallClass, GetActorTransform());

	FVector fireballVeloResult;
	fireball->GetSuggestVelocity(fireballVeloResult, TargetLocation);
	if (GEngine)
	{
		FString Msg = fireballVeloResult.ToString();
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, Msg);
	}

	fireball->GetSphere()->AddImpulse(fireballVeloResult);

	//fireball->GetSphere()->AddImpulse()

}

void AFlameBeast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
