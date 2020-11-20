#include "pch.h"
#include "Engine/Graphics/Renderer.h"
#include "Engine\Graphics\Program.h"

int main(int argc, char** argv)
{
	nc::Renderer renderer;
	renderer.StartUp();
	renderer.Create("OpenGL", 800, 600);

	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	};

	nc::Program program;
	program.CreateShaderFromFile("shaders\\basic.vert", GL_VERTEX_SHADER);
	program.CreateShaderFromFile("shaders\\basic.frag", GL_FRAGMENT_SHADER);
	program.Link();
	program.Use();

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		SDL_PumpEvents();
		
		renderer.BeginFrame();

		//render triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);

		renderer.EndFrame();


	}

	return 0;
}
