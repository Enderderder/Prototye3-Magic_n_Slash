// Fill out your copyright notice in the Description page of Project Settings.

#include "FireBall.h"

#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFireBall::AFireBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	RootComponent = SphereCollider;

	FireBallParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireBallParticle"));
	FireBallParticle->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFireBall::BeginPlay()
{
	Super::BeginPlay();
	



}

// Called every frame
void AFireBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/// Tick is off
}
