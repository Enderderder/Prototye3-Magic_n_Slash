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

protected:
	// Called when the game starts or when spawnesd
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
