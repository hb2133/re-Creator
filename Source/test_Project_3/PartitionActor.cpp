// Fill out your copyright notice in the Description page of Project Settings.


#include "PartitionActor.h"

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
	

}
