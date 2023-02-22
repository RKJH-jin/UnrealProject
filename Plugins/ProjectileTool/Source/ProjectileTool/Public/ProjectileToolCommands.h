// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ProjectileToolStyle.h"

class FProjectileToolCommands : public TCommands<FProjectileToolCommands>
{
public:

	FProjectileToolCommands()
		: TCommands<FProjectileToolCommands>(TEXT("ProjectileTool"), NSLOCTEXT("Contexts", "ProjectileTool", "ProjectileTool Plugin"), NAME_None, FProjectileToolStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};