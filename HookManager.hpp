#pragma once

#include <vector>
#include "Hook.hpp"

namespace ziapi {
	
	class AHookManager {
		public:
			AHookManager();
			~AHookManager() = default;

			/**
			 * addHook
			 * Add a hook in the hookManager
			 * @param: hook to add
			 * @return true if the add is successfull otherwise it will return false
			*/
			virtual bool	addHook(ziapi::Hook &) = 0;

			/**
			 * unHook
			 * remove a hook of the hookManager
			 * @param: hook to remove
			 * @return true if the remove is successfull otherwise it will return false
			*/
			virtual void	unHook(ziapi::Hook &) = 0;

			/**
			 * runHooks
			 * run hooks
			 * @param: hook moment to run
			 * @param: the command to process (ex: request, response, encrypted string)
			 * @return the callStatus of the hooks called
			*/
			virtual ziapi::CallStatus	runHooks(const ziapi::CallOn, ziapi::Command &) = 0;


			/**
			 * getHooks
			 * @return the hooks unordered_map
			*/
			const std::unordered_map<ziapi::CallOn, std::vector<ziapi::Hook>>	&getHooks() const noexcept { return hooks; }
		private:
			std::unordered_map<ziapi::CallOn, std::vector<ziapi::Hook>>	hooks = {
				{ziapi::CallOn::connect, {}},
				{ziapi::CallOn::preparsing, {}},
				{ziapi::CallOn::preprocessing, {}},
				{ziapi::CallOn::postprocessing, {}},
				{ziapi::CallOn::disconnect, {}}
			};
	};

} // ziapi
