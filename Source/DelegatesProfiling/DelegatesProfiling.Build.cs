// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DelegatesProfiling : ModuleRules
{
    public DelegatesProfiling(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
        });
    }
}