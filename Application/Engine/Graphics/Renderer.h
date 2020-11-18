#pragma once
#include "../Core/System.h"
#include <SDL.h>
#include <string>

namespace nc
{
	class Renderer : public System
	{
	public:

		// Inherited via System
		virtual bool StartUp() override;

		virtual void ShutDown() override;

		virtual void Update() override;

		bool Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

		friend class Texture;

	protected:
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
		SDL_GLContext m_context;
	};

}