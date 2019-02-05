#pragma once

#include <string>
#include <unordered_map>
#include <variant>

namespace ziapi {
	
	struct Request {
		std::string	method;
		std::string	uri;
		std::string	version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							message_body;
	};

	struct Response {
		int		code;
		std::string	message;
		std::string	version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							message_body;
	};

	struct Command {
		Request	request;
		Response	response;
		std::string	encryption;
	};

} // ziapi
