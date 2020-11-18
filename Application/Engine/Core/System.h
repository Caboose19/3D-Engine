#pragma once

namespace nc
{
	class System
	{
	public:
		virtual	bool StartUp() = 0;
		virtual	void ShutDown() = 0;
		virtual	void Update() = 0;

	};
}