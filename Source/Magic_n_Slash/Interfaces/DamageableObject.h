// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageableObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageableObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAGIC_N_SLASH_API IDamageableObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ReceiveDamage(float _value, bool _bApplyLaunch, FVector _hitDirection, float _hitPower);
	virtual void ReceiveDamage_Implementation(float _value, bool _bApplyLaunch, FVector _hitDirection, float _hitPower);

	
};
