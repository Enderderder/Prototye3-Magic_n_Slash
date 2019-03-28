// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireBall.generated.h"

UCLASS()
class MAGIC_N_SLASH_API AFireBall : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* FireBallParticle;

public:	
	// Sets default values for this actor's properties
	AFireBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Getter Section */
	UFUNCTION(BlueprintCallable)
	FORCEINLINE class USphereComponent* GetSphere() { return SphereCollider; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE class UParticleSystemComponent* GetParticleComponent() { return FireBallParticle; }
	/** End Getter Section */


};
