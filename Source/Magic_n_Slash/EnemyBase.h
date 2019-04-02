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

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* TargetingIndicator;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* HealthIndicator;
	
public:
	// Sets default values for this character's properties
	AEnemyBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat | General")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat | General")
	float CurrHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat | Status")
	bool bStaggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat | Status")
	bool bAlive;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// BlueprintNativeEvent that gets the perception location and rotation of the enemy
	UFUNCTION(BlueprintNativeEvent, Category = "AIPerception | Character")
	void GetPerceptionLocRot(FVector& Location, FRotator& Rotation) const;
	void GetPerceptionLocRot_Implementation(FVector& Location, FRotator& Rotation) const;

	UFUNCTION(BlueprintCallable)
	virtual void KillObject();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnObjectKilled"))
	void Receive_OnObjectKilled();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to get the eye view point of the character
	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;

	UFUNCTION(BlueprintCallable)
	virtual void OnTargeted();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnTargeted"))
	void Receive_OnTargeted();

	UFUNCTION(BlueprintCallable)
	virtual void OnUnTargeted();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnUnTargeted"))
	void Receive_OnUnTargeted();
};
