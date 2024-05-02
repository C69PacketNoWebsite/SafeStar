#pragma once
#include "Utils/ProcessManager.hpp"
#include "MenuConfig.hpp"

class SafeManager {
public:
	template <typename ReadType>
	bool SafeWrite(DWORD64 address, ReadType& value, int size) {
		if (MenuConfig::SafeMode) return false;
		return ProcessMgr.WriteMemory<ReadType>(address, value, size);
	}

	template <typename ReadType>
	bool SafeWrite(DWORD64 address, ReadType& value) {
		if (MenuConfig::SafeMode) return false;
		return ProcessMgr.WriteMemory<ReadType>(address, value);
	}
};

inline SafeManager SafeMgr;