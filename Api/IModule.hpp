//
// EPITECH PROJECT, 2019
// 
// File description:
// 
//

#pragma once

#include <type_traits>
#include <unordered_map>
#include <string>

namespace Ziapi
{
	
	enum Processing
	{
		PREPROCESSING,
		POSTPROCESSING,
		BOTH
	};

	struct ModuleData
	{
		int prePriority;
		int postPriority;
		Processing callMoment;
	};
	
	struct Response
	{
		int code;
		std::string reason;
		std::string version;
		std::unordered_map<std::string, std::string> headers;
		std::string msgBody;
	};
	
	class IModule
	{
	public:
		virtual ~IModule() = default;
		virtual const ModuleData getModuleData() const noexcept = 0;
		virtual std::conditional<true, std::string, Response> run(const std::conditional<true, std::string, Response> &input) = 0;
	};
};
