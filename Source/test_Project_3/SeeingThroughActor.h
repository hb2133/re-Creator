// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeeingThroughActor.generated.h"

UCLASS()
class TEST_PROJECT_3_API ASeeingThroughActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASeeingThroughActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetShowSeeingThrough(bool bThroughShow);

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* SeeingTroughMesh;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float SeeingThroughTime;

	bool bSeeingThrough;

	float RunningTimer;
};
