// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RoomManager.h"
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
	TArray<AActor*> MapTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* m_PartitionBaseActor;
	UFUNCTION(BlueprintCallable)
		AActor* RandomMapTemplate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		TArray<FSpawnOrder> enemyList;
};
