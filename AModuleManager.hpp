#pragma once

#include <vector>
#include "HookManager.hpp"

namespace ziapi {
	
	class AModuleManager {
		public:
			virtual ~AModuleManager() = default;

			virtual bool	loadModule(const std::string &) = 0;
			virtual bool	unloadModule(const std::string &) = 0;

			virtual ziapi::AHookManager	&getHookManager() noexcept = 0;
	};

} // ziapi