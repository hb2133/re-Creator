// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "MyEffect.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapAreaEffect.generated.h"

UENUM(BlueprintType)
enum class EEFFECTTYPE : uint8
{
	BUFF, DEBUFF,
};

UCLASS()
class TEST_PROJECT_3_API AMapAreaEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapAreaEffect();
	virtual ~AMapAreaEffect();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual AMyEffect* SpawnEffect(AActor* target, AMyEffect* effectActor, UPARAM(ref) float& ref_val, float effect, float duration);
	UFUNCTION(BlueprintCallable)
		virtual void ClearEffect() const;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "type")
	EEFFECTTYPE m_Type;
	AMyEffect* m_Effect;
};
