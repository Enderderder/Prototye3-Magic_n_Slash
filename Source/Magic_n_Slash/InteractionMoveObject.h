// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionMoveObject.generated.h"

UCLASS()
class MAGIC_N_SLASH_API AInteractionMoveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionMoveObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	FVector MoveToOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	TMap<class AInteractableObject*, bool> InteractConditions;

	UPROPERTY(BlueprintReadWrite, Category = "Moving")
	bool ConditionsMet;

	UPROPERTY(BlueprintReadWrite, Category = "Moving")
	bool IsActivated;

	UPROPERTY(EditAnywhere, Category = "Moving")
	float MoveTime;

#pragma region MoveTimelineVariables
	UPROPERTY()
	FVector startPosition;

	UPROPERTY()
	FVector endPosition;

	UPROPERTY()
	class UTimelineComponent* MoveTimeLine;

	UPROPERTY(EditAnywhere, Category = "Moving: Timeline")
	class UCurveFloat* MoveFloatCurve;

	// Declare delegate function to be binded with TimelineFloatReturn(float _value)
	class FOnTimelineFloat* InterpFunction;

	// Declare deletgate function to be binded with OnTimelineFinished()
	class FOnTimelineEvent* TimelineFinished;
#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveToOffsetPosition();
	UFUNCTION(BlueprintImplementableEvent, Category = "Moving", meta = (DisplayName = "OnMoveToOffsetPosition"))
	void Receive_MoveToOffsetPosition();

	UFUNCTION()
	void MoveToOriginalPosition();
	UFUNCTION(BlueprintImplementableEvent, Category = "Moving", meta = (DisplayName = "OnMoveToOriginPosition"))
	void Recieve_MoveToOriginalPosition();

	UFUNCTION(BlueprintCallable)
	void CheckIsActivated();

#pragma region MoveTimelineFunctions
	UFUNCTION(BlueprintCallable)
	void SetTimelineValues();

	UFUNCTION()
	void OnTimelineUpdate(float _value);

	UFUNCTION()
	void OnTimelineFinished();
#pragma endregion
};
