// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MyLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class TEST_PROJECT_3_API AMyLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> m_Partition;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		int m_mapSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		int m_distance;

	
	TArray<TArray<AActor*>> m_MapPositions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* m_PartitionBaseActor;
};
