#pragma once

#include <functional>
#include "ZiapiHeader.hpp"

namespace ziapi {


	/**
	 * CallOn
	 * There is many times to call modules:
	 * connect: when a client is connecting on the server
	 * preparsing: call just before the parsing, thoose modules use a string (ex: decryption module)
	 * preprocessing: call before the processing of the http request, thoose modules use a Request struc (ex: log module)
	 * postprocessing: call after the processing of the http request, thoose modules use a Response struc (ex: php module)
	 * disconnect: when a client is disconnecting from the server
	*/
	enum CallOn {
		connect,
		preparsing,
		preprocessing,
		postprocessing,
		disconnect,
	};

	/**
	 * CallStatus
	 * Modules return type
	*/
	enum CallStatus {
		OK,
		ERROR,
	};

	/**
	 * Priority
	 * FIRST: the hook is called in first
	 * BEFORE_MIDDLE: the hook is called after the first and before middle hooks
	 * MIDDLE: if we dont care of the hook call order
	 * AFTER_MIDDLE: after middle hooks and before the last hook
	 * LAST: the hook is called in last
	*/
	enum Priority {
		FIRST,
		BEFORE_MIDDLE,
		MIDDLE,
		AFTER_MIDDLE,
		LAST,
	};


	/**
	 * Hook
	 * moduleName: is the name of the module; a module can have many hooks
	 * callMoment: is the moment where ths hook will be call
	 * Priority: is the priority of call of the hook
	 * function: its the hook function to call
	*/
	struct Hook {
		std::string							moduleName;
		CallOn							callMoment;
		Priority							priority;
		std::function<CallStatus(ziapi::Command &)>	function;

		bool	operator==(const Hook &other) const {
			return moduleName.compare(other.moduleName);
		}
	};

} // ziapi
