// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BurnableGrassPatch.generated.h"

UCLASS()
class MAGIC_N_SLASH_API ABurnableGrassPatch : public AActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInstancedStaticMeshComponent* LotsOfGrassComponent;

public:	
	// Sets default values for this actor's properties
	ABurnableGrassPatch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
