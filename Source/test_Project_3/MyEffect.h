// Fill out your copyright notice in the Description page of Project Settings.

#include<functional>
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEffect.generated.h"

UCLASS()
class TEST_PROJECT_3_API AMyEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyEffect();
	virtual ~AMyEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EffectApply();
	virtual void EffectClear();

	UFUNCTION(BlueprintCallable)
		AActor* getTarget() const;
	UFUNCTION(BlueprintCallable)
		void setTarget(AActor* Target);


	UFUNCTION(BlueprintCallable)
		float getEffectVal() const;
	UFUNCTION(BlueprintCallable)
		 AMyEffect* setEffectVal(float val);

	UFUNCTION(BlueprintCallable)
		float getDuration() const;
	UFUNCTION(BlueprintCallable)
		 AMyEffect* setDuration(float val);

	UFUNCTION(BlueprintCallable)
		float getBeforeVal() const;
	UFUNCTION(BlueprintCallable)
		 AMyEffect* setBeforeVal(float val);

	UFUNCTION(BlueprintCallable)
		void ApplyFunc() const;

		 AMyEffect* SetApplyFunc(std::function<void()> val);

	UFUNCTION(BlueprintCallable)
		void ClearFunc() const;

		 AMyEffect* setClearFunc(std::function<float()> val);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		class AActor* applyTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		float effectVal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		float duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
	float beforeVal;
	
		std::function<void()> applyFunc;
		std::function<float()> clearFunc;

};
