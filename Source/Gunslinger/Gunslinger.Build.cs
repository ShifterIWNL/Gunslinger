// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Gunslinger : ModuleRules
{
	public Gunslinger(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {"GameplayTasks", "GameplayAbilities", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
