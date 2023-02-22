// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectileToolCommands.h"

#define LOCTEXT_NAMESPACE "FProjectileToolModule"

void FProjectileToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "ProjectileTool", "Bring up ProjectileTool window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
