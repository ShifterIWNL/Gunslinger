// Copyright Epic Games, Inc. All Rights Reserved.

#include "GunslingerGameMode.h"
#include "GunslingerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGunslingerGameMode::AGunslingerGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}
