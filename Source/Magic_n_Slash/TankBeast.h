// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "TankBeast.generated.h"

/**
 * 
 */
UCLASS()
class MAGIC_N_SLASH_API ATankBeast : public AEnemyBase
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* MeleeHitBox;

public:
	// Sets default values for this character's properties
	ATankBeast();

	// Combat sensors

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | Sense")
	float MeleeRange;

	// Melee attack
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | Config")
	float MeleeDamage;

protected:
	// Called when the game starts or when spawnesd
	virtual void BeginPlay() override;

	/** EnemyBase Interface */
	virtual void ReceiveDamage_Implementation(float _value, bool _bApplyLaunch, FVector _hitDirection, float _hitPower) override;
	/** Interface End */


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
