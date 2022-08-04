// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelScriptActor.h"
#include "PartitionActor.h"
#include<any>
void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	

	
}

// Called every frame
void AMyLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

AActor* AMyLevelScriptActor::RandomMapTemplate()
{
	int32 num = FMath::RandRange(0, MapTemplate.Num()-1);

	TArray<EROOMTYPE> roomTypes{ EROOMTYPE::BOSS,EROOMTYPE::MONSTER,EROOMTYPE::SHOP };

	int8 typsNum = FMath::RandRange(0, roomTypes.Num() - 1);

	return MapTemplate[num];
}
