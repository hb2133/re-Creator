// Fill out your copyright notice in the Description page of Project Settings.


#include "AEffectApply.h"
// Sets default values

AAEffectApply::AAEffectApply()
	:applyTarget{ nullptr }, effectVal{ 0 }, duration{0}
{

	PrimaryActorTick.bCanEverTick = true;

}


//AAEffectApply::AAEffectApply(AActor* Target,  float effect, float duration)
//	:applyTarget{ Target }, effectVal{ effect }, duration{ duration }, applyFunc{ nullptr }, clearFunc{ nullptr }
//{
//	
//	PrimaryActorTick.bCanEverTick = true;
//}

//AAEffectApply::~AAEffectApply()
//{
//	//EffectClear();
//	UE_LOG(LogTemp, Log, TEXT("AAEffectApply dest : %d"),1234);
//}

// Called when the game starts or when spawned
void AAEffectApply::BeginPlay()
{
	
	
}

// Called every frame
void AAEffectApply::Tick(float DeltaTime)
{

	
}
//void AAEffectApply::EffectApply()
//{
//	ApplyFunc();
//}
//
//void AAEffectApply::EffectClear()
//{
//	ClearFunc();
//}

void AAEffectApply::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("AAEffectApply dest : %d"), 1234);
}

AActor* AAEffectApply::getTarget() const
{
	return applyTarget;
}

void AAEffectApply::setTarget(AActor* Target)
{
	applyTarget = Target;
}


float AAEffectApply::getEffectVal() const
{
	return effectVal;
}

const AAEffectApply* AAEffectApply::setEffectVal(float val)
{
	effectVal = val;
	return this;
}

float AAEffectApply::getDuration() const
{
	return duration;
}

const AAEffectApply* AAEffectApply::setDuration(float val)
{
	duration = val;
	return this;
}

//void AAEffectApply::ApplyFunc() const
//{
//	applyFunc();
//}
//
//const AAEffectApply* AAEffectApply::SetApplyFunc(std::function<void()> val)
//{
//	applyFunc = val;
//	//ApplyFunc();
//	return this;
//}
//
//
//
//void AAEffectApply::ClearFunc() const
//{
//	clearFunc();
//}
//
//const AAEffectApply* AAEffectApply::setClearFunc(std::function<void()> val)
//{
//	clearFunc = val;
//	return this;
//}


