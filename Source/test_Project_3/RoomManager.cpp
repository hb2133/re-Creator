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


	std::priority_queue<FSpawnOrder> newOrderQ;
	const int check = 100;
	const int max_cost = 1000;


	TArray<FSpawnOrder> orderArray;
	for (int i = 0; i < world->enemyList.Num(); ++i) {
		for (int j = 0; j < (check / world->enemyList[i].cost); ++j) {
			orderArray.Emplace(world->enemyList[i]);
		}
	}

	{
		FSpawnOrder targetOrder;

		for (int i = max_cost; i > 0; ) {
			int32 num = FMath::RandRange(0, orderArray.Num() - 1);

			targetOrder = orderArray[num];
			targetOrder.count = FMath::RandRange(5, 30);

			UE_LOG(LogTemp, Log, TEXT("targetOrder: %d"), targetOrder.count);
			int culCost = targetOrder.cost * targetOrder.count;

			i -= culCost;
			if (i < culCost) {
				for (int j = i; j > culCost;) {
					culCost = culCost - targetOrder.cost;
					targetOrder.count--;
				}
			}

			newOrderQ.emplace(targetOrder);
		}
	}
	RoomStatus.CurrentMonsters.Empty();
	for (int i = newOrderQ.size(); i > 0; i--) {
		UE_LOG(LogTemp, Log, TEXT("%d"), newOrderQ.top().count);
		RoomStatus.CurrentMonsters.Add(newOrderQ.top());
		newOrderQ.pop();
	}


		
	UE_LOG(LogTemp, Log, TEXT("orderQ size : %d"), newOrderQ.size());
	UE_LOG(LogTemp, Log, TEXT("orderQ cost : %d"), newOrderQ.top().cost);

	


	
	

}


bool FSpawnOrder::operator<(const FSpawnOrder& target) const
{
	return target.cost < cost;

}
