#pragma once

#include <vector>
#include "Hook.hpp"

namespace ziapi {
	
	class AHookManager {
		public:
			AHookManager();
			~AHookManager() = default;

			virtual bool	addHook(ziapi::Hook &) = 0;

			virtual void	unHook(ziapi::Hook &) = 0;

			virtual ziapi::CallStatus	runHooks(const ziapi::CallOn, ziapi::Command &) = 0;


			const std::unordered_map<ziapi::CallOn, std::vector<ziapi::Hook>>	&getHooks() const noexcept { return hooks; }
		private:
			std::unordered_map<ziapi::CallOn, std::vector<ziapi::Hook>>	hooks = {
				{ziapi::CallOn::connect, {}},
				{ziapi::CallOn::preparsing, {}},
				{ziapi::CallOn::prerequest, {}},
				{ziapi::CallOn::postrequest, {}},
				{ziapi::CallOn::disconnect, {}}
			};
	};

} // ziapi
