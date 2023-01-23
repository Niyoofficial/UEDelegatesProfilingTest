using UnrealBuildTool;

public class DelegatesTests : ModuleRules
{
    public DelegatesTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bUseUnity = false;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "DelegatesProfiling"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "DeveloperSettings"
        });
    }
}