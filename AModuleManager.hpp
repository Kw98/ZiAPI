#pragma once

#include <vector>
#include "HookManager.hpp"

namespace ziapi {
	
	class AModuleManager {
		public:
			virtual ~AModuleManager() = default;

			/**
			 * loadModule
			 * load a module from the full path of the lib
			 * @param full path of the lib to load
			 * @return true if the load if successfull otherwise its return false
			*/
			virtual bool	loadModule(const std::string &) = 0;

			/**
			 * unloadModule
			 * unload a module with the full path of the lib
			 * @param full path of the lib to unload
			 * @return true if the unload if successfull otherwise its return false
			*/
			virtual bool	unloadModule(const std::string &) = 0;


			/**
			 * getHookManager
			 * return the hookmanager
			 * @return hookmanager
			*/
			virtual ziapi::AHookManager	&getHookManager() noexcept = 0;
	};

} // ziapi