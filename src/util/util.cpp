#include "util.h"

namespace util {
    uintptr_t findSig(HMODULE hModule, const char* signature) {
        if (!hModule) return 0;

        std::vector<int> sequence;
        for (const char* p = signature; *p; ++p) {
            if (*p == ' ' || *p == '\t') continue;
            if (*p == '?') {
                ++p;
                if (*p == '?') ++p;
                sequence.push_back(-1);
            }
            else sequence.push_back(std::strtoul(p, const_cast<char**>(&p), 16));
        }

        PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)hModule + ((PIMAGE_DOS_HEADER)hModule)->e_lfanew);
        std::uint8_t* startAddress = (std::uint8_t*)hModule;
        std::uint8_t* endAddress = startAddress + ntHeaders->OptionalHeader.SizeOfImage - sequence.size();

        for (std::uint8_t* p = startAddress; p < endAddress; ++p) {
            bool found = true;
            for (size_t i = 0; i < sequence.size(); ++i) {
                if (sequence[i] != -1 && p[i] != sequence[i]) {
                    found = false;
                    break;
                }
            }
            if (found) return reinterpret_cast<uintptr_t>(p);
        }

        return 0;
    }
}