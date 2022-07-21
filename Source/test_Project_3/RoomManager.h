// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "PartitionActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomManager.generated.h"




USTRUCT(BlueprintType)
struct FRoomStatus {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		TArray<AActor*> CurrentMonsters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		int level;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		static int ClearCost;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		FRoomNode current;*/

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
		FRoomStatus ManagerInfo;

	UFUNCTION(BlueprintCallable)
		void setInfoRoom(APartitionActor* actor);

	UFUNCTION(BlueprintCallable)
		int getClearCost() const;
	UFUNCTION(BlueprintCallable)
		void setClearCost(int num);

};
