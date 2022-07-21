// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomTriggerBase.h"

// Sets default values
ARoomTriggerBase::ARoomTriggerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoomTriggerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoomTriggerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FRoomNode& ARoomTriggerBase::setInfo(const FRoomNode& input)
{
	InfoRoom.nextMap = input.nextMap;
	InfoRoom.nextMapTrigger = input.nextMapTrigger;
	InfoRoom.eDir = input.eDir;
	InfoRoom.roomType = input.roomType;


	return InfoRoom;
}

void ARoomTriggerBase::setPartAct(ARoomTriggerBase* input)
{
	PartitionActor = input->PartitionActor;
}

