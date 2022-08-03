// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomTriggerBase.h"
#include "PartitionActor.h"

#include "Runtime/Engine/public/EngineUtils.h"
// Sets default values
APartitionActor::APartitionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
}

// Called when the game starts or when spawned
void APartitionActor::BeginPlay()
{
	Super::BeginPlay();


	UWorld* CurrentWorld = GetWorld();
	
	
	
	
	
}

// Called every frame
void APartitionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}

void APartitionActor::setRoom()
{
	if (roomDir.up.nextMap != nullptr) {
		roomTriggerDir.up.nextMap = roomDir.up.nextMap;
	}
	if (roomDir.down.nextMap != nullptr) {
		roomTriggerDir.down.nextMap = roomDir.down.nextMap;
	}
	if (roomDir.right.nextMap != nullptr) {
		roomTriggerDir.right.nextMap = roomDir.right.nextMap;
	}
	if (roomDir.left.nextMap != nullptr) {
		roomTriggerDir.left.nextMap = roomDir.left.nextMap;
	}
}

FString APartitionActor::ContainName(AActor* inputActor
	,const FString& up, const FString& down , const FString& right, const FString& left )
{
	

	if (inputActor->GetName().Contains(up)) {
		return const_cast<FString&>(up);
	}
	else if (inputActor->GetName().Contains(down)) {
		return const_cast<FString&>(down);
	}
	else if (inputActor->GetName().Contains(right)) {
		return const_cast<FString&>(right);
	}
	else if (inputActor->GetName().Contains(left)) {
		return const_cast<FString&>(left);
	}


	return FString();
}

FDirect& APartitionActor::TriggerDirAdd(AActor* element, EDIRECT dir)
{
	switch (dir) {
	case EDIRECT::UP:
		roomTriggerDir.up.nextMapTrigger = element;
		roomTriggerDir.up.eDir = EDIRECT::UP;
		break;
	case EDIRECT::DOWN:
		roomTriggerDir.down.nextMapTrigger = element;
		roomTriggerDir.down.eDir = EDIRECT::DOWN;
		break;
	case EDIRECT::RIGHT:
		roomTriggerDir.right.nextMapTrigger = element;
		roomTriggerDir.right.eDir = EDIRECT::RIGHT;
		break;
	case EDIRECT::LEFT:
		roomTriggerDir.left.nextMapTrigger = element;
		roomTriggerDir.left.eDir = EDIRECT::LEFT;
		break;
	case EDIRECT::CURRENT:
		roomTriggerDir.current.nextMapTrigger = element;
		roomTriggerDir.current.eDir = EDIRECT::CURRENT;
		break;
	}
	return roomTriggerDir;
}

FDirect& APartitionActor::SetNextMap(FDirect input, FDirect target)
{
	target.up.nextMap = input.up.nextMap;
	target.down.nextMap = input.down.nextMap;
	target.right.nextMap = input.right.nextMap;
	target.left.nextMap = input.left.nextMap;
	target.current.nextMap = input.current.nextMap;
	return target;
}

TArray<AActor*> APartitionActor::AddTrigger(AActor* input)
{
	if (input == nullptr) return Triggers;
	
	

	Triggers.AddUnique(input);

	return Triggers;
}

void APartitionActor::Duplicate(AActor* a)
{
	
	
	
}

