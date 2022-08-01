// Fill out your copyright notice in the Description page of Project Settings.

#include <iostream>
#include<queue>
#include<vector>
#include"MyLevelScriptActor.h"

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
	return RoomStatus.ClearCost;
}

void ARoomManager::setClearCost(int num)
{
	RoomStatus.ClearCost += num;
}



void ARoomManager::RandomEnemyOrder()
{
	auto w = this->GetLevel()->GetLevelScriptActor();
	auto world = Cast<AMyLevelScriptActor>(w);

	if (w == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("w is nullptr, roomManager"));
		return;
	}
	if (world == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("world is nullptr, roomManager"));
		return;
	}


	std::priority_queue<FSpawnOrder> orderQ;

	for (auto& item : world->enemyList) {
		orderQ.emplace(item);
	}

	for (int i = orderQ.size(); i > 0; i--) {
		UE_LOG(LogTemp, Log, TEXT("%d"), orderQ.top().count);
		RoomStatus.CurrentMonsters.Add(orderQ.top());
		orderQ.pop();
	}
	
	auto amount = 1000 / orderQ.size();

	auto count = amount / orderQ.top().cost;




	
	

}


bool FSpawnOrder::operator<(const FSpawnOrder& target) const
{
	return target.cost < cost;

}
