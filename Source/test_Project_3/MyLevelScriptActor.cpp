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
	
	return MapTemplate[num];
}
