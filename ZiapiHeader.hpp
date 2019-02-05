#pragma once

#include <string>
#include <unordered_map>
#include <variant>

namespace ziapi {
	
	/**
	 * Request
	 * Http request structure
	*/
	struct Request {
		std::string	method;
		std::string	uri;
		std::string	version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							message_body;
	};

	/**
	 * Response
	 * Http response structure
	*/
	struct Response {
		int		code;
		std::string	message;
		std::string	version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							message_body;
	};

	/**
	 * Command
	 * is the command to be processed by the hooks
	 * request: request struct, it will be used by preprocessing hooks
	 * response: response struct, it will be used by postprocessing hooks
	 * encryption: string, it will be used by preparsing hooks (the ssl encryption is on the whole request not only the msg_body)
	*/
	struct Command {
		Request	request;
		Response	response;
		std::string	encryption;
	};

} // ziapi
