//
// EPITECH PROJECT, 2019
// 
// File description:
// 
//

#pragma once

#include "IModule.hpp"

namespace Ziapi
{

	class IZiapi
	{
	public:
		virtual ~IZiapi() = default;
		virtual std::string		&runPreparsingModules(std::string &) = 0;
		virtual Ziapi::request_s	&runPreprocessingModules(Ziapi::request_s &) = 0;
		virtual Ziapi::response_s	&runPostprocessingModules(Ziapi::response_s &) = 0;

		virtual bool loadModule(const std::string &name) = 0;
		virtual bool unloadModule(const std::string &name) = 0;
	private:
		virtual void setPriority(Ziapi::IModule module) = 0;
	};
};
