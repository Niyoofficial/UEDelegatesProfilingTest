# UEDelegatesProfilingTest

This repository is an unreal project containing a set of a simple automation tests with a purpose to measure unreal delegate system perfomance.
Each test first binds a function to the delegate and than the delegate is broadcasted 1 milion times.

There are currently 4 tests implemented:
- Raw function bound with **AddUObject** to **Multicast Delegate** - Test Name: **Delegates.Multicast.UObject**
- UFUNCTION decorated function bound with **AddUFunction** to **Multicast Delegate** - Test Name: **Delegates.Multicast.UFunction**
- UFUNCTION decorated function bound with **AddDynamic** macro to **Dynamic Multicast Delegate** - Test Name: **Delegates.DynamicMulticast.UFunction**
- Blueprint Event bound with **Bind Event to... BP node** to **Dynamic Multicast Delegate** - Test Name: **Delegates.DynamicMulticast.BPEvent**

## Running the tests

### Editor
There are editor automation test plugins enabled in the project to easily run the tests from the editor

<img width="188" alt="image" src="https://user-images.githubusercontent.com/49919817/213947092-43d05684-2142-4622-829e-2ff123f805f6.png"> <img width="600" alt="image" src="https://user-images.githubusercontent.com/49919817/213946994-1d5cd5d8-795a-4eb6-b335-c34f23c2a158.png">

### Command Line
If you want to run the test without the editor fluff the command is:

```
"[PathToProject]DelegatesProfiling.uproject" -unattended -game -nullrhi -execcmds="Automation RunTests [TestName]" -log
```
## Compiling
The project is provided with precompiled binaries for Win64 in Development Editor configuraion
