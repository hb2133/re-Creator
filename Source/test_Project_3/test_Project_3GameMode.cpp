// Copyright Epic Games, Inc. All Rights Reserved.

#include "test_Project_3GameMode.h"
#include "test_Project_3Character.h"
#include "UObject/ConstructorHelpers.h"

Atest_Project_3GameMode::Atest_Project_3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
