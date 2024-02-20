// Copyright Epic Games, Inc. All Rights Reserved.

#include "Practica1GameMode.h"
#include "Practica1PlayerController.h"
#include "Practica1Character.h"
#include "UObject/ConstructorHelpers.h"

APractica1GameMode::APractica1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APractica1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}