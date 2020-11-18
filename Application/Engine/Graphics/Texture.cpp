#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "Texture.h"
#include "Renderer.h"

namespace nc {
	bool Texture::Create(const std::string& name, void* renderer)
	{

		m_renderer = static_cast<Renderer*>(renderer)->m_renderer;

		SDL_Surface* surface = nullptr;//IMG_Load(name.c_str());
		if (surface == nullptr)
		{
			return false;
		}
		m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		SDL_FreeSurface(surface);
		if (m_texture == nullptr)
		{
			return false;
		}
		return true;
	}

	void Texture::Destory()
	{
		SDL_DestroyTexture(m_texture);
	}


}
	