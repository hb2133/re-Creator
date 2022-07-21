// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartitionActor.h"
#include "RoomTriggerBase.generated.h"

UCLASS()
class TEST_PROJECT_3_API ARoomTriggerBase : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Map", meta = (AllowPrivateAccess = "true"))
		FRoomNode InfoRoom;
public:	
	// Sets default values for this actor's properties
	ARoomTriggerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Map" )
		AActor* PartitionActor;


	UFUNCTION(BlueprintCallable)
		FRoomNode& setInfo(const FRoomNode& input);
	UFUNCTION(BlueprintCallable)
		void setPartAct(ARoomTriggerBase* input);

};
