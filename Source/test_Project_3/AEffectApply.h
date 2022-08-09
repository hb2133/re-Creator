// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include<functional>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AEffectApply.generated.h"

UCLASS()
class TEST_PROJECT_3_API AAEffectApply : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AAEffectApply();
	//~AAEffectApply();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*virtual void EffectApply();
	virtual void EffectClear();*/
	virtual void Destroyed();


	UFUNCTION(BlueprintCallable)
	AActor* getTarget() const;
	UFUNCTION(BlueprintCallable)
	void setTarget(AActor* Target);
	

	UFUNCTION(BlueprintCallable)
		float getEffectVal() const;
	UFUNCTION(BlueprintCallable)
		const AAEffectApply* setEffectVal(float val);

	UFUNCTION(BlueprintCallable)
		float getDuration() const;
	UFUNCTION(BlueprintCallable)
		const AAEffectApply* setDuration(float val);

	/*UFUNCTION(BlueprintCallable)
		void ApplyFunc() const;

		const AAEffectApply* SetApplyFunc(std::function<void()> val);

	UFUNCTION(BlueprintCallable)
		void ClearFunc() const;

		const AAEffectApply* setClearFunc(std::function<void()> val);*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		class AActor* applyTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		float effectVal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "effect")
		float duration;

		
		std::function<void()> applyFunc;
		std::function<float()> clearFunc;
};
