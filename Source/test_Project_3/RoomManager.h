// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "PartitionActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomManager.generated.h"



USTRUCT(BlueprintType)
struct FSpawnOrder {

	GENERATED_BODY()
public:

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		UClass* enemyClass;

	bool operator<(const FSpawnOrder& target) const;
		
};

USTRUCT(BlueprintType)
struct FRoomStatus {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		TArray<FSpawnOrder> CurrentMonsters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int cost = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int level = 0;
	
		static int ClearCost;
	
};

UCLASS()
class TEST_PROJECT_3_API ARoomManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Map", meta = (AllowPrivateAccess = "true"))
	FDirect InfoRoom;

public:	
	// Sets default values for this actor's properties
	ARoomManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		APartitionActor* PartitionActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomStatus RoomStatus;

	UFUNCTION(BlueprintCallable)
		void setInfoRoom(APartitionActor* actor);

	UFUNCTION(BlueprintCallable)
		int getClearCost() const;
	UFUNCTION(BlueprintCallable)
		void setClearCost(int num);

	UFUNCTION(BlueprintCallable)
		void RandomEnemyOrder();
	

};
