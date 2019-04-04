// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBeast.h"

#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"

ATankBeast::ATankBeast()
{
	MeleeHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MeleeHitBox"));
	MeleeHitBox->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
}

void ATankBeast::BeginPlay()
{
	Super::BeginPlay();

}

void ATankBeast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
