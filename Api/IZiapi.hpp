//
// EPITECH PROJECT, 2019
// 
// File description:
// 
//

#pragma once

namespace Ziapi
{

	class IZiapi
	{
	public:
		virtual ~IZiapi() = default;
		virtual std::string runPreprocessingModules(std::string &request) = 0;
		virtual Response runPostprocessingModules(Response &response) = 0;
		virtual bool loadModule(const std::string &name) = 0;
		virtual bool unloadModule(const std::string &name) = 0;
	private:
		virtual void setPriority(IModules module) = 0;
	};
};
