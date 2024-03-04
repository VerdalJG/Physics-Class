// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhysicsFinalGameMode.h"
#include "PhysicsFinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhysicsFinalGameMode::APhysicsFinalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
