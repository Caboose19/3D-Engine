#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "InputSystem.h"

namespace nc
{
	bool InputSystem::StartUp()
	{
		//get current keystate and retrieve num keys
		const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);

		//allocate memoryfor current and previous keystate
		m_keystate = new Uint8[m_numKeys];
		m_prevKeystate = new Uint8[m_numKeys];
		//copy current keystaet (source) to m_keystate (destnation)
		memcpy(m_keystate, keystate, m_numKeys);

		memcpy(m_prevKeystate, keystate, m_numKeys);
		return true;
	}
	void InputSystem::ShutDown()
	{
		delete[]m_keystate;
		delete[]m_prevKeystate;
	}
	void InputSystem::Update()
	{
		memcpy(m_prevKeystate, m_keystate, m_numKeys);

		const Uint8* keystate = SDL_GetKeyboardState(nullptr);

		memcpy(m_keystate, keystate, m_numKeys);
	}

	bool InputSystem::GetButtonDown(int id)
	{
		return m_keystate[id];
	}

	bool InputSystem::GetPreviousButtonDown(int id)
	{
		return m_prevKeystate[id];
	}

	InputSystem::eButtonSate InputSystem::GetButtonState(int id)
	{
		InputSystem::eButtonSate state = InputSystem::eButtonSate::IDLE;

		bool buttonDown = GetButtonDown(id);
		
		bool prevButtonDown = GetPreviousButtonDown(id);

		if (buttonDown)
		{
			state = (prevButtonDown) ?	eButtonSate::HELD: eButtonSate::PRESSED;
		}
		else
		{
			state = (prevButtonDown) ? eButtonSate::REALEASED : eButtonSate::IDLE;
		}

		return state;

	}

	
 }
