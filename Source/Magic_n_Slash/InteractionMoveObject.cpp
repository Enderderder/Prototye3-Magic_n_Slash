// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionMoveObject.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
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

#pragma region SetupMoveTimeline
	PrimaryActorTick.bCanEverTick = true;

	MoveTimeLine = CreateDefaultSubobject<UTimelineComponent>(TEXT("Timeline"));

	InterpFunction->BindUFunction(this, FName("OnTimelineUpdate"));
	TimelineFinished->BindUFunction(this, FName("OnTimelineFinished"));

	if (MoveFloatCurve)
	{
		MoveTimeLine->AddInterpFloat(MoveFloatCurve, *InterpFunction, FName("Alpha"));
		MoveTimeLine->SetTimelineFinishedFunc(*TimelineFinished);

		startPosition = GetActorLocation();

		SetTimelineValues();

		MoveTimeLine->SetLooping(false);
		MoveTimeLine->SetIgnoreTimeDilation(true);
	}
#pragma endregion
}

// Called every frame
void AInteractionMoveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractionMoveObject::MoveToOffsetPosition()
{
	Receive_MoveToOffsetPosition();

	if (!IsActivated)
	{
		IsActivated = true;
		MoveTimeLine->Play();
	}
}

void AInteractionMoveObject::MoveToOriginalPosition()
{
	Recieve_MoveToOriginalPosition();

	if (IsActivated)
	{
		IsActivated = false;
		MoveTimeLine->Reverse();
	}
}

void AInteractionMoveObject::CheckIsActivated()
{
	ConditionsMet = true;
	
	for (const TPair<AInteractableObject*, bool>& pair : InteractConditions)
	{
		if (pair.Key->IsActivated != pair.Value)
		{
			ConditionsMet = false;
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

void AInteractionMoveObject::SetTimelineValues()
{
	endPosition = startPosition + MoveToOffset;

	MoveTimeLine->SetPlayRate(1.0f / MoveTime);
}

void AInteractionMoveObject::OnTimelineUpdate(float _value)
{
	SetActorLocation(FMath::Lerp(startPosition, endPosition, _value));
}

void AInteractionMoveObject::OnTimelineFinished()
{

}
