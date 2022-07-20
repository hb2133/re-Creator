// Fill out your copyright notice in the Description page of Project Settings.


#include "PartitionActor.h"
#include "Runtime/Engine/public/EngineUtils.h"
// Sets default values
APartitionActor::APartitionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* SphereComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	//SetFolderPath("MapPartition");

	
}

// Called when the game starts or when spawned
void APartitionActor::BeginPlay()
{
	Super::BeginPlay();


	UWorld* CurrentWorld = GetWorld();

	
	
	//for (auto i : m_maps) {
	//	FVector Fvec = FVector(GetActorLocation());

	//	FRotator Frot = GetTransform().Rotator();
	//	FActorSpawnParameters Fparam = FActorSpawnParameters();
	//	Fparam.Template = i;
	//	auto actor = GetWorld()->SpawnActor<AActor>(Fvec,Frot,Fparam);
	//	
	//	//actor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	//	
	//
	//}
	
}

// Called every frame
void APartitionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*UWorld* CurrentWorld = GetWorld();

	TArray<AActor*> objs;
	pivotActor->GetAttachedActors(objs);*/
	//pivotActor->GetDefaultSubobjects(objs);
	/*UE_LOG(LogTemp, Warning, TEXT("%d"), CurrentWorld->GetActorCount());
	for (const auto& i : objs) {

		UE_LOG(LogTemp, Warning, TEXT("%s"),*i->GetName());
	}*/
	
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
	,const FString& up, const FString& down, const FString& right, const FString& left)
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

FDirect& APartitionActor::dirAdd(AActor* element, EDIRECT dir)
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
	}
	return roomTriggerDir;
}

