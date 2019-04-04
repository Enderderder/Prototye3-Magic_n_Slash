// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GodaiGamemode.generated.h"

/**
 * 
 */
UCLASS()
class MAGIC_N_SLASH_API AGodaiGamemode : public AGameModeBase
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CheckPoint", meta = (AllowPrivateAccess = "true"))
	TArray<class ASimpleCheckPoint*> CheckPoints;

public:
	// Default constructer
	AGodaiGamemode();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CheckPoint")
	int32 CurrentCheckPointIndex;

protected:

	// Called after find all the check points, sort it
	void PlaceCheckPointAndSort(TArray<AActor*> _inArray);

public:

	/** AActor Interface */
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	/** End Interface */

	/** AGamemodeBase Interface */
	virtual void StartPlay() override;
	/** End Interface */


	/** Getter Functions */
	UFUNCTION()
	FORCEINLINE TArray<class ASimpleCheckPoint*> GetCheckPoints() { return CheckPoints; }
	/** Getter End */

};
