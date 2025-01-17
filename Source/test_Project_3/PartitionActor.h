// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartitionActor.generated.h"


UENUM(BlueprintType)
enum class EDIRECT : uint8 {
	UP UMETA(DisplayName = "Up"),
	DOWN UMETA(DisplayName = "Down"),
	RIGHT UMETA(DisplayName = "Right"),
	LEFT UMETA(DisplayName = "Left"),
	CURRENT UMETA(DisplayName = "Current"),
};

UENUM(BlueprintType)
enum class EROOMTYPE : uint8 {
	MONSTER UMETA(DisplayName = "Monster"),
	SHOP UMETA(DisplayName = "Shop"),
	BOSS UMETA(DisplayName = "Boss"),
	
};

USTRUCT(Atomic, BlueprintType)
struct FRoomNode {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* nextMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor* nextMapTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		EDIRECT eDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		EROOMTYPE roomType;

};

USTRUCT(Atomic, BlueprintType)
struct FDirect {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomNode up;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomNode down;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomNode right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomNode left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		FRoomNode current;
	
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

	UFUNCTION(BlueprintCallable)
		void setRoom();

	UFUNCTION(BlueprintCallable)
		FString ContainName(AActor* inputActor
			,const FString& up, const FString& down, const FString& right, const FString& left);
	UFUNCTION(BlueprintCallable)
		FDirect& TriggerDirAdd(AActor* element, EDIRECT dir);

	UFUNCTION(BlueprintCallable)
		FDirect& SetNextMap(FDirect input, FDirect target);

	UFUNCTION(BlueprintCallable)
		TArray<AActor*> AddTrigger(AActor* input);
	UFUNCTION(BlueprintCallable)
		void Duplicate(AActor* a);



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		AActor * pivotActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		TArray<AActor*> maps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map")
		TArray<AActor*> Triggers;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		FDirect roomDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
		FDirect roomTriggerDir;
	



};


