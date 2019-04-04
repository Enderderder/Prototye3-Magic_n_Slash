// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "FlameBeast.generated.h"

/**
 * 
 */
UCLASS()
class MAGIC_N_SLASH_API AFlameBeast : public AEnemyBase
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* MeleeHitBox;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* FireBallLauchPoint;


public:
	// Sets default values for this character's properties
	AFlameBeast();

	// Combat sensors

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | Sense")
	float MeleeRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | Sense")
	float FireBallRange;

	// Range attack
		// Fire ball class
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | Range")
	TSubclassOf<class AFireBall> FireBallClass;

	// Melee attack
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | General")
	float MeleeDamage;

protected:
	// Called when the game starts or when spawnesd
	virtual void BeginPlay() override;

	// Call the Shoot Fire ball with target lock
	UFUNCTION(BlueprintCallable, Category = "Combat | Range")
	void LaunchFireBallToLocation(FVector TargetLocation);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
