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

	MeleeHitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ATankBeast::ReceiveDamage_Implementation(float _value, bool _bApplyLaunch, FVector _hitDirection, float _hitPower)
{
	Super::ReceiveDamage_Implementation(_value, _bApplyLaunch, _hitDirection, _hitPower);
}

void ATankBeast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
