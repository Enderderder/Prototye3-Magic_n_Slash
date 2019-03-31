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

	IsMovementLocked = false;
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

	if (!IsMovementLocked)
	{
		if (ConditionsMet)
		{
			MoveToOffsetPosition();
		}
		else
		{
			MoveToOriginalPosition();
		}
	}
}

void AInteractionMoveObject::LerpMoveTransform(FTransform _startTransform, float _alpha, FTransform& _updatedTransform)
{
	if (IsCurrentPosStart)
	{
		_updatedTransform.SetLocation(FMath::Lerp(_startTransform.GetLocation(), MoveToOffset.GetLocation(), _alpha));
		_updatedTransform.SetRotation(FMath::Lerp(_startTransform.GetRotation(), MoveToOffset.GetRotation(), _alpha));
		_updatedTransform.SetScale3D(FMath::Lerp(_startTransform.GetScale3D(), MoveToOffset.GetScale3D(), _alpha));
	}
	else
	{
		_updatedTransform.SetLocation(FMath::Lerp(MoveToOffset.GetLocation(), _startTransform.GetLocation(), _alpha));
		_updatedTransform.SetRotation(FMath::Lerp(MoveToOffset.GetRotation(), _startTransform.GetRotation(), _alpha));
		_updatedTransform.SetScale3D(FMath::Lerp(MoveToOffset.GetScale3D(), _startTransform.GetScale3D(), _alpha));
	}
}
