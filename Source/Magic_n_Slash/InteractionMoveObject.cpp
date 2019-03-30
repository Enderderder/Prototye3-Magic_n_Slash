// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionMoveObject.h"
#include "InteractableObject.h"

// Sets default values
AInteractionMoveObject::AInteractionMoveObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractionMoveObject::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AInteractionMoveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractionMoveObject::MoveToOffsetPosition()
{
	Receive_MoveToOffsetPosition();
}

void AInteractionMoveObject::MoveToOriginalPosition()
{
	Recieve_MoveToOriginalPosition();
}

void AInteractionMoveObject::CheckIsActivated()
{
	ConditionsMet = true;
	
	for (const TPair<AInteractionMoveObject*, bool>& pair : InteractConditions)
	{
		if (pair.Key != nullptr)
		{
			if (pair.Key->InteractableIsActive != pair.Value)
			{
				ConditionsMet = false;
			}
		}
	}

	if (ConditionsMet)
	{
		MoveToOffsetPosition();
	}
	else
	{
		MoveToOriginalPosition();
	}
}

FVector AInteractionMoveObject::LerpMovePos(FVector _startPos, float _alpha)
{
	if (IsCurrentPosStart)
	{
		return (FMath::Lerp(_startPos, MoveToOffset, _alpha));
	}
	else
	{
		return (FMath::Lerp(MoveToOffset, _startPos, _alpha));
	}
}
