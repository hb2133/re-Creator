// Fill out your copyright notice in the Description page of Project Settings.


#include "MapAreaEffect.h"
#include "MyEffect.h"

// Sets default values
AMapAreaEffect::AMapAreaEffect()
	:m_Effect{nullptr}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

AMapAreaEffect::~AMapAreaEffect()
{
}

// Called when the game starts or when spawned
void AMapAreaEffect::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMapAreaEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AMyEffect* AMapAreaEffect::SpawnEffect(AActor* target,AMyEffect* effectActor, UPARAM(ref) float& ref_val, float effect, float duration)
{
	if (m_Effect != nullptr) return m_Effect;

	if (effectActor == nullptr) {
		auto ef = GetWorld()->SpawnActor<AMyEffect>();
		m_Effect = ef;
	}
	else { m_Effect = effectActor; }

	UE_LOG(LogTemp, Log, TEXT("Func SpawnEffect dest : %d"), effect);

	return m_Effect;
}

void AMapAreaEffect::ClearEffect() const
{
	//m_Effect->ClearFunc();
	UE_LOG(LogTemp, Log, TEXT("Func ClearEffect dest : %d"), 5);


}

