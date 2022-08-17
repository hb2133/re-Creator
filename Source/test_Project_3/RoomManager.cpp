// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomManager.h"
#include <iostream>
#include<queue>
#include<vector>
#include"MyLevelScriptActor.h"

// Sets default values
// 
// 
// 
// 
int ARoomManager::ClearCost = 0;
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
	return ClearCost;
}

void ARoomManager::setClearCost(int num)
{
	ClearCost += num;
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


	TArray<FSpawnOrder> newOrderQ;
	const int check = 100;
	const int max_cost = 500;


	TArray<FSpawnOrder> orderArray;
	for (int i = 0; i < world->enemyList.Num(); ++i) {
		for (int j = 0; j < (check / world->enemyList[i].cost); ++j) {
			orderArray.Emplace(world->enemyList[i]);
		}
		UE_LOG(LogTemp, Log, TEXT("orderNum : %d"), (check / world->enemyList[i].cost));
	}

	{
		FSpawnOrder targetOrder;

		for (int i = max_cost; i > 0; ) {
			int32 num = FMath::RandRange(0, orderArray.Num() - 1);

			targetOrder = orderArray[num];
			int max = (60 / targetOrder.cost);
			targetOrder.count = FMath::RandRange(1, max);

			UE_LOG(LogTemp, Log, TEXT("targetOrdercost: %d"), targetOrder.cost);
			UE_LOG(LogTemp, Log, TEXT("targetOrdercount: %d"), targetOrder.count);
			int culCost = targetOrder.cost * targetOrder.count;

			i -= culCost;
			if (i < culCost) {
				for (int j = i; j > culCost;) {
					culCost = culCost - targetOrder.cost;
					targetOrder.count--;
				}
			}

			newOrderQ.Emplace(targetOrder);
		}
	}
	RoomStatus.CurrentMonsters.Empty();

	for (auto var :newOrderQ)
	{
		UE_LOG(LogTemp, Log, TEXT("%d"), var.cost);
		RoomStatus.CurrentMonsters.Add(var);
	}




	UE_LOG(LogTemp, Log, TEXT("orderQ size : %d"), newOrderQ.Num());
	UE_LOG(LogTemp, Log, TEXT("orderQ cost : %d"), newOrderQ[0].cost);
	
	

}


bool FSpawnOrder::operator<(const FSpawnOrder& target) const
{
	return target.cost < cost;

}
