#pragma once

#include <Windows.h>
#include <vector>

namespace util {
	uintptr_t findSig(HMODULE hModule, const char* signature);
}