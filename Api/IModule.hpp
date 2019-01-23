//
// EPITECH PROJECT, 2019
// 
// File description:
// 
//

#pragma once

#include <type_traits>
#include <unordored_map>
#include <string>

namespace Ziapi
{
	
	enum Processing
	{
		PREPROCESSING,
		POSTPROCESSING,
		BOTH
	};
	
	struct ModulesData
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
		std::unordored_map<std::string, std::string> headers;
		std::string msgBody;
	};
	
	class IModule
	{
	public:
		virtual ~IModule() = default;
		virtual const ModuleData getModuleData() const noexept = 0;
		virtual std::conditionnal<true, std::string, Response> run(const std::conditionnal<true, std::string, Response> &input) = 0;
	};
};
