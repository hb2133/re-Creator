// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelScriptActor.h"
#include "PartitionActor.h"
#include<any>
void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	

	
}

// Called every frame
void AMyLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

AActor* AMyLevelScriptActor::RandomMapTemplate()
{
	int32 num = FMath::RandRange(0, MapTemplate.Num()-1);

	TArray<EROOMTYPE> roomTypes{ EROOMTYPE::BOSS,EROOMTYPE::MONSTER,EROOMTYPE::SHOP };

	int8 typsNum = FMath::RandRange(0, roomTypes.Num() - 1);

	return MapTemplate[num];
}

UClass* AMyLevelScriptActor::RandomAreaEffect()
{
	int32 num = FMath::RandRange(0, AreaEffectList.Num() - 1);

	/*for (auto area : MapAreaList) {
		if (area->m_Effect != nullptr) {
			area->m_Effect->Destroy();
		}
	}
	auto world = GetWorld();*/

	/*for (auto part : PartitionList) {
		num = FMath::RandRange(0, AreaEffectList.Num() - 1);
		auto trans = part->GetTransform();

		
		auto area = world->SpawnActor<AMapAreaEffect>(AreaEffectList[num]->StaticClass());
		area->SetActorTransform(trans);


	}*/

	/*float temp = 1.0f;
	for (auto area : MapAreaList) {

		num = FMath::RandRange(0, AreaEffectList.Num() - 1);

		auto effect = GetWorld()->SpawnActor(AreaEffectList[num]);
		auto eft = Cast<AMyEffect>(effect);
		area->SpawnEffect(area,eft , temp, temp, temp);
	}*/
	return AreaEffectList[num];
}


