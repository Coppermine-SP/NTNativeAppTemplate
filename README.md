# NTNativeAppTemplate
<img src="https://img.shields.io/badge/c-064F8C?style=for-the-badge&logo=c&logoColor=white">

**Template for Windows NT Native Subsystem Application.**

<img src="img/sample.png" style="width: 80%">

Win32 Subsystem을 사용하지 않는 NT Native 프로그램을 제작하기 위한 템플릿입니다.

> [!Warning]
> **Target OS가 Test Signing Mode를 요구할 수 있습니다.**
> 
> 강화된 Windows 보안 정책으로 인해 코드 서명되지 않은 BootExecution 바이너리에 대한 실행이 거부될 수 있습니다.

**Prerequisites**
- Visual Studio 2022
- Windows Software Development Kits (with VS extensions)

Native Application의 진입점은 WinMain 또는 Main 대신에, NtProcessStartup입니다. 또한 Win32 프로그램과 달리 반환할 런타임 코드가 없기 때문에 NtProcessTerminate()를 통해 스스로 종료해야 합니다.

템플릿은 기본적으로 NtDisplayString()을 통해 부트 스크린에 Hello, World를 출력한 후, 일정 시간을 대기하고 반환하는 코드를 포함하고 있습니다.

## NT Native Application이란 무엇입니까?

<img src="img/windows_architecture.png">

NT Native Application은 Win32와 같은 Environment Subsystem 없이 User Mode에서 직접 실행되는 Application을 의미합니다. (대표적으로 csrss.exe, smss.exe)

**즉, Windows API를 사용하지 않고 NT Native API (ntdll.dll)를 직접 사용합니다.**

일반적으로 Native Image는 smss.exe가 세션 초기화를 마치면 더 이상 로드 할 수 없기 때문에, BootExecute로 실행되어야 합니다. (HKLM/SYSTEM/CurrentControlSet/Session Manager/BootExecute)

즉, Win32 Subsystem이 준비되기 전의 Windows 시스템의 초기 단계에 실행됩니다.

> [!NOTE]
> **Native Applications에 대한 자세한 사항은, 아래 Microsoft 문서를 참조하십시오:**
>
> https://learn.microsoft.com/en-us/sysinternals/resources/inside-native-applications
