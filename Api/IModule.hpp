//
// EPITECH PROJECT, 2019
// 
// File description:
// 
//

#pragma once

#include <unordered_map>
#include <string>

namespace Ziapi
{
	enum hooks_e {
		hook_pre_parsing,
		hook_pre_processing,
		hook_post_processing
	};

	struct module_informations_s {
		hooks_e type;
		int	priority;
	};
	
	struct response_s {
		int								code;
		std::string							reason;
		std::string							version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							msg_body;
	};

	struct request_s {
		std::string							method;
		std::string							uri;
		std::string							version;
		std::unordered_map<std::string, std::string>	headers;
		std::string							msg_body;
	};

	class IModule
	{
	public:
		virtual ~IModule() = default;
		virtual const module_informations_s getModuleInformations() const noexcept = 0;

		virtual request_s		&run(request_s &) = 0;
		virtual response_s	&run(response_s &) = 0;
		virtual std::string	&run(std::string &) = 0;
	};
};
