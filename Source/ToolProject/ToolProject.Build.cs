// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ToolProject : ModuleRules
{
	public ToolProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

		PrivateIncludePaths.Add("ToolProject");
	}
}
