// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.generated.h"

UCLASS()
class MAGIC_N_SLASH_API AInteractableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableObject();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool IsUseable;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool IsActivated;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
