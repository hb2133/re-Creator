// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelScriptActor.h"
#include "PartitionActor.h"
#include<any>
void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	UWorld* world = GetWorld();
	

	m_MapPositions.AddDefaulted(m_mapSize);
	/*for (size_t h = 0; h < m_mapSize; ++h)
	{
		for (size_t w = 0; w < m_mapSize; ++w)
		{

			FVector Fvec = FVector(m_PartitionBaseActor->GetTransform().GetLocation().X+(h*m_distance)
				, m_PartitionBaseActor->GetTransform().GetLocation().Y+ (w * m_distance)
				, m_PartitionBaseActor->GetTransform().GetLocation().Z);

			FRotator Frot = m_PartitionBaseActor->GetTransform().Rotator();
			m_MapPositions[h].Add(world->SpawnActor<AActor>(APartitionActor::StaticClass(), Fvec, Frot));
			
			m_MapPositions[h][w]->AttachToActor(m_PartitionBaseActor,FAttachmentTransformRules::KeepWorldTransform);
		
		}
	
	}*/
	
	
	

	
}

// Called every frame
void AMyLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}
