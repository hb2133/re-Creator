// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomManager.h"
// Sets default values
// 
// 
// 
// 
int FRoomStatus::ClearCost = 0;
ARoomManager::ARoomManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ARoomManager::BeginPlay()
{
	Super::BeginPlay();

	if (PartitionActor != nullptr) {
		InfoRoom.up.nextMapTrigger = PartitionActor->roomTriggerDir.up.nextMapTrigger;
		InfoRoom.down.nextMapTrigger = PartitionActor->roomTriggerDir.down.nextMapTrigger;
		InfoRoom.right.nextMapTrigger = PartitionActor->roomTriggerDir.right.nextMapTrigger;
		InfoRoom.left.nextMapTrigger = PartitionActor->roomTriggerDir.left.nextMapTrigger;
	}

}

// Called every frame
void ARoomManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoomManager::setInfoRoom(APartitionActor* actor)
{
	if (actor != nullptr) {
		InfoRoom.up.nextMapTrigger = PartitionActor->roomTriggerDir.up.nextMapTrigger;
		InfoRoom.down.nextMapTrigger = PartitionActor->roomTriggerDir.down.nextMapTrigger;
		InfoRoom.right.nextMapTrigger = PartitionActor->roomTriggerDir.right.nextMapTrigger;
		InfoRoom.left.nextMapTrigger = PartitionActor->roomTriggerDir.left.nextMapTrigger;
	}
}

int ARoomManager::getClearCost() const
{
	return ManagerInfo.ClearCost;
}

void ARoomManager::setClearCost(int num)
{
	ManagerInfo.ClearCost += num;
}


