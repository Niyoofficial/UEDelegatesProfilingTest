// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DelegatesTestObject.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class DELEGATESTESTS_API UDelegatesTestObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BindToTestDelegate();

	void RawTestFunction();
	UFUNCTION()
	void UFunctionTestFunction();

public:
	TMulticastDelegate<void()> testMulticastDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDynamicMulticast);

	UPROPERTY(BlueprintAssignable)
	FTestDynamicMulticast testDynamicMulticastDelegate;
};
