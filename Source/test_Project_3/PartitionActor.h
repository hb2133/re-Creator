// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
	
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartitionActor.generated.h"


USTRUCT(Atomic, BlueprintType)
struct FDirect {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* up;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* down;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* left;
};

UCLASS()
class TEST_PROJECT_3_API APartitionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APartitionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor * pivotActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
	TArray<AActor*> maps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FDirect roomDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FDirect roomTriggerDir;
};


