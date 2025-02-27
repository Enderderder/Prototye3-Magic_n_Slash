// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/DamageableObject.h"
#include "EnemyBase.generated.h"

UCLASS()
class MAGIC_N_SLASH_API AEnemyBase : public ACharacter, public IDamageableObject
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat: General")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat: General")
	float CurrHealth;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// BlueprintNativeEvent that gets the perception location and rotation of the enemy
	UFUNCTION(BlueprintNativeEvent, Category = "AIPerception | Character")
	void GetPerceptionLocRot(FVector& Location, FRotator& Rotation) const;
	void GetPerceptionLocRot_Implementation(FVector& Location, FRotator& Rotation) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to get the eye view point of the character
	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;


};
