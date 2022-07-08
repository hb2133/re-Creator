// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class test_Project_3 : ModuleRules
{
	public test_Project_3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
