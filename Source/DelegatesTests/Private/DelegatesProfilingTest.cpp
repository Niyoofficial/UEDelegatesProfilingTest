#include "DelegatesTestObject.h"
#include "DelegatesTestsSettings.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDelegatesTest, Display, Display);
DEFINE_LOG_CATEGORY(LogDelegatesTest);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMulticastUObjectTest, "Delegates.Multicast.UObject",
								 EAutomationTestFlags::ApplicationContextMask |
								 EAutomationTestFlags::HighPriority |
								 EAutomationTestFlags::PerfFilter)

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMulticastUFunctionTest, "Delegates.Multicast.UFunction",
								 EAutomationTestFlags::ApplicationContextMask |
								 EAutomationTestFlags::HighPriority |
								 EAutomationTestFlags::PerfFilter)

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDynamicMulticastUFunctionTest, "Delegates.DynamicMulticast.UFunction",
								 EAutomationTestFlags::ApplicationContextMask |
								 EAutomationTestFlags::HighPriority |
								 EAutomationTestFlags::PerfFilter)

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDynamicMulticastBPEventTest, "Delegates.DynamicMulticast.BPEvent",
								 EAutomationTestFlags::ApplicationContextMask |
								 EAutomationTestFlags::HighPriority |
								 EAutomationTestFlags::PerfFilter)


namespace
{
	constexpr int64 numberOfIterations = 1000000;

	template<typename T>
	bool DoDelegateTest(FAutomationTestBase& test,
						FString testHeader,
						std::function<void(UDelegatesTestObject*)> setupFunction,
						T UDelegatesTestObject::* delegatePtr)
	{
		if (TSubclassOf<UDelegatesTestObject> testObjClass = UDelegatesTestsSettings::Get()->delegatesTestObjectClass)
		{
			auto* testObj = NewObject<UDelegatesTestObject>(GetTransientPackage(), testObjClass);
			if (!IsValid(testObj))
				return false;

			test.AddInfo(testHeader);

			setupFunction(testObj);

			uint64 testStartTime = FPlatformTime::Cycles64();

			for (int32 i = 0; i < numberOfIterations; ++i)
			{
				(testObj->*delegatePtr).Broadcast();
			}

			uint64 testStopTime = FPlatformTime::Cycles64();
			double testTime = FPlatformTime::ToMilliseconds64(testStopTime - testStartTime);

			FString outputString = FString::Format(
				TEXT("{0} broadcasts took {1} ms, average {2} ms per broadcast"),
				{numberOfIterations, testTime, testTime / numberOfIterations});

			test.AddInfo(outputString);

			return true;
		}
		return false;
	}
}

bool FMulticastUObjectTest::RunTest(const FString& parameters)
{
	return DoDelegateTest(*this, TEXT("Mutlicast Delegate - AddUObject"),
						  [](UDelegatesTestObject* testObj)
						  {
							  testObj->testMulticastDelegate.AddUObject(testObj, &UDelegatesTestObject::RawTestFunction);
						  }, &UDelegatesTestObject::testMulticastDelegate);
}

bool FMulticastUFunctionTest::RunTest(const FString& parameters)
{
	return DoDelegateTest(*this, TEXT("Mutlicast Delegate - AddUFunction"),
						  [](UDelegatesTestObject* testObj)
						  {
							  testObj->testMulticastDelegate.AddUFunction(testObj, "UFunctionTestFunction");
						  }, &UDelegatesTestObject::testMulticastDelegate);
}

bool FDynamicMulticastUFunctionTest::RunTest(const FString& parameters)
{
	return DoDelegateTest(*this, TEXT("Dynamic Mutlicast Delegate - AddDynamic"),
						  [](UDelegatesTestObject* testObj)
						  {
							  testObj->testDynamicMulticastDelegate.AddDynamic(
								  testObj, &UDelegatesTestObject::UFunctionTestFunction);
						  }, &UDelegatesTestObject::testDynamicMulticastDelegate);
}

bool FDynamicMulticastBPEventTest::RunTest(const FString& parameters)
{
	return DoDelegateTest(*this, TEXT("Dynamic Mutlicast Delegate - Blueprint Event"),
						  [](UDelegatesTestObject* testObj)
						  {
							  testObj->BindToTestDelegate();
						  }, &UDelegatesTestObject::testDynamicMulticastDelegate);
}
