// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBase.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetingIndicator = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetingIndicator"));
	TargetingIndicator->SetupAttachment(GetMesh());

	HealthIndicator = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthIndicator"));
	HealthIndicator->SetupAttachment(RootComponent);
	HealthIndicator->SetGenerateOverlapEvents(false);
	HealthIndicator->SetWidgetSpace(EWidgetSpace::Screen);

}

void AEnemyBase::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	/// Not using parent class implementation

	GetPerceptionLocRot(Location, Rotation);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Set default values
	CurrHealth = MaxHealth;
	bAlive = true;
	bStaggered = false;


	

}

void AEnemyBase::GetPerceptionLocRot_Implementation(FVector& Location, FRotator& Rotation) const
{
	Location = GetActorLocation() + FVector(0.0f, 0.0f, 80.0f);
	Rotation = GetActorRotation();
}

void AEnemyBase::KillObject()
{



	Receive_OnObjectKilled();
}

void AEnemyBase::OnTargeted()
{
	TargetingIndicator->SetVisibility(true);

	Receive_OnTargeted();
}

void AEnemyBase::OnUnTargeted()
{
	TargetingIndicator->SetVisibility(false);

	Receive_OnUnTargeted();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}