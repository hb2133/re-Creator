// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffect.h"

// Sets default values
AMyEffect::AMyEffect()
	:applyTarget{ nullptr }, effectVal{ 0 }, duration{ 0 },beforeVal{0}, applyFunc{nullptr}, clearFunc{nullptr}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AMyEffect::~AMyEffect()
{

		UE_LOG(LogTemp, Log, TEXT("AMyEffect dest : %d"),1234);
}

// Called when the game starts or when spawned
void AMyEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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


void AMyEffect::EffectApply()
{
	ApplyFunc();
}

void AMyEffect::EffectClear()
{
	ClearFunc();
}



AActor* AMyEffect::getTarget() const
{
	return applyTarget;
}

void AMyEffect::setTarget(AActor* Target)
{
	applyTarget = Target;
}


float AMyEffect::getEffectVal() const
{
	return effectVal;
}

 AMyEffect* AMyEffect::setEffectVal(float val)
{
	effectVal = val;
	return this;
}

float AMyEffect::getDuration() const
{
	return duration;
}

 AMyEffect* AMyEffect::setDuration(float val)
{
	duration = val;
	return this;
}

float AMyEffect::getBeforeVal() const
{
	return beforeVal;
}

AMyEffect* AMyEffect::setBeforeVal(float val)
{
	beforeVal = val;
	return this;
}


void AMyEffect::ApplyFunc() const
{
	applyFunc();
}

 AMyEffect* AMyEffect::SetApplyFunc(std::function<void()> val)
{
	applyFunc = val;

	return this;
}



void AMyEffect::ClearFunc() const
{
	clearFunc();
}

 AMyEffect* AMyEffect::setClearFunc(std::function<float()> val)
{
	clearFunc = val;
	return this;
}

