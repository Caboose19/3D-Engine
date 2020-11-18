#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "Renderer.h"

bool nc::Renderer::StartUp()
{
	//IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	
	return true;
}

void nc::Renderer::ShutDown()
{	
}

void nc::Renderer::Update()
{
}

bool nc::Renderer::Create(const std::string& name, int width, int height)
{
	 m_window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_OPENGL);

	if (m_window == nullptr) {
		SDL_Log("Failed to create window %s", SDL_GetError);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetSwapInterval(1);
	
	m_context = SDL_GL_CreateContext(m_window);
	if (!gladLoadGL())
	{
		SDL_Log("Failed to create OpenGL context");
		exit(-1);
	}

	return true;
}

void nc::Renderer::BeginFrame()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//begin of frame
}

void nc::Renderer::EndFrame()
{
	SDL_GL_SwapWindow(m_window);
	//end of frame
}
