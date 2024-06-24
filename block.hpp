#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>


void block_loadlibrary() {

	HMODULE kernel32 = GetModuleHandleA("kernel32.dll");

	if (kernel32 == NULL) return;

	std::vector<const char*> names = { "LoadLibraryA","LoadLibraryW","LoadLibraryExA","LoadLibraryExW"};

	const int RET = 0xC3;

	for (auto& name : names)
	{
		uintptr_t loadlibrary = (uintptr_t)GetProcAddress(kernel32, name);
		WriteProcessMemory(GetCurrentProcess(), (void*)(loadlibrary), &RET, sizeof(RET), NULL);
	}
}
