#pragma once

#include <functional>
#include "ZiapiHeader.hpp"

namespace ziapi {

	enum CallOn {
		connect,
		preparsing,
		prerequest,
		postrequest,
		disconnect,
	};

	enum CallStatus {
		OK,
		ERROR,
	};

	enum Priority {
		FIRST,
		BEFORE_MIDDLE,
		MIDDLE,
		AFTER_MIDDLE,
		LAST,
	};

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
