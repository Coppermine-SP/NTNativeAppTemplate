/*
 *	NtMain.c - NtNativeAppTemplate
 *	Copyright (C) 2024-2025 Coppermine-SP.
 */
#include <Windows.h>
#include <winternl.h>
#define NtCurrentProcess() ((HANDLE)((LONG_PTR)-1))

NTSYSAPI NTSTATUS NTAPI NtDisplayString(PUNICODE_STRING DisplayString);
NTSYSAPI NTSTATUS NTAPI NtTerminateProcess(HANDLE ProcessHandle, NTSTATUS ExitStatus);
NTSYSAPI NTSTATUS NTAPI NtDelayExecution(IN BOOLEAN Alertable, IN PLARGE_INTEGER DelayInterval);

//Entry Point
VOID NtProcessStartup(PPEB args)
{
	//Print HelloWorld via NtDisplayString.
	UNICODE_STRING str;
	RtlInitUnicodeString(&str, L"Hello, World from NT Native!\n");
	NtDisplayString(&str);

	//Delay execution.
	LARGE_INTEGER delay = { 0 };
	delay.QuadPart = -150000000;
	NtDelayExecution(FALSE, &delay);

	//Terminate process.
	NtTerminateProcess(NtCurrentProcess(), 0);
}