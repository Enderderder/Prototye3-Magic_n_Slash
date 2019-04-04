// Fill out your copyright notice in the Description page of Project Settings.

#include "GodaiGamemode.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

#include "SimpleCheckPoint.h"

AGodaiGamemode::AGodaiGamemode()
{

}

void AGodaiGamemode::PlaceCheckPointAndSort(TArray<AActor*> _inArray)
{
	for (AActor* obj : _inArray)
	{
		CheckPoints.Add(Cast<ASimpleCheckPoint>(obj));
	}

	CheckPoints.Sort([](const ASimpleCheckPoint& A, const ASimpleCheckPoint& B)
	{
		return A.CheckPointIndex < B.CheckPointIndex;
	});

	for (ASimpleCheckPoint* obj : CheckPoints)
	{
		//FString text = obj->CheckPointIndex.ToString();

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, text);
	}


}

void AGodaiGamemode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ResultArray;
	UGameplayStatics::GetAllActorsOfClass(this, ASimpleCheckPoint::StaticClass(), ResultArray);
	PlaceCheckPointAndSort(ResultArray);
}

void AGodaiGamemode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

void AGodaiGamemode::StartPlay()
{
	Super::StartPlay();


}
