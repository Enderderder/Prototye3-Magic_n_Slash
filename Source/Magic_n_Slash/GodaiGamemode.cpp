// Fill out your copyright notice in the Description page of Project Settings.

#include "GodaiGamemode.h"

#include "Kismet/GameplayStatics.h"
#include "Engine.h"

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

}

void AGodaiGamemode::BeginPlay()
{
	Super::BeginPlay();

	CurrentCheckPointIndex = 0;

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
