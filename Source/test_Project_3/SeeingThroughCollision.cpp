// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Classes/Components/BoxComponent.h"
#include "SeeingThroughCollision.h"
#include "test_Project_3Character.h"
#include "SeeingThroughActor.h"

// Sets default values
ASeeingThroughCollision::ASeeingThroughCollision()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SeeingThroughCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("SeeingThroughCollision"));
	RootComponent = SeeingThroughCollision;
	SeeingThroughCollision->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));

}

// Called when the game starts or when spawned
void ASeeingThroughCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASeeingThroughCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASeeingThroughCollision::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Atest_Project_3Character* Character = Cast<Atest_Project_3Character>(OtherActor);
	if (Character)
	{
		for (auto SeeingThroughActor : SeeingThroughActors)
		{
			SeeingThroughActor->SetShowSeeingThrough(true);
		}
	}
}

void ASeeingThroughCollision::NotifyActorEndOverlap(AActor* OtherActor)
{
	Atest_Project_3Character* Character = Cast<Atest_Project_3Character>(OtherActor);
	if (Character)
	{
		for (auto SeeingThroughActor : SeeingThroughActors)
		{
			SeeingThroughActor->SetShowSeeingThrough(false);
		}
	}
}
