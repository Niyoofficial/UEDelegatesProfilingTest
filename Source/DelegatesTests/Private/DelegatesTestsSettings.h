#pragma once

#include "CoreMinimal.h"
#include "DelegatesTestsSettings.generated.h"

/**
 *
 */
UCLASS(Config = Game, DefaultConfig)
class DELEGATESTESTS_API UDelegatesTestsSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    static const UDelegatesTestsSettings* Get() { return GetDefault<UDelegatesTestsSettings>(); }

protected:
    virtual FName GetContainerName() const override { return "Project"; }
    virtual FName GetCategoryName() const override { return "Game"; }

public:
    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<class UDelegatesTestObject> delegatesTestObjectClass;
};