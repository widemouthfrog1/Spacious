#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPACIOUS_API __declspec(dllexport)
	#else
		#define SPACIOUS_API __declspec(dllimport)
	#endif
#else
	#error Spacious currently only supports Windows
#endif