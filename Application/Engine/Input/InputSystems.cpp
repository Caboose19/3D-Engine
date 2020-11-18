#include "C:\Users\Zach\source\repos\3D Engine\Application\pch.h"
#include "InputSystems.h"

namespace nc
{
	bool InputSystems::StartUp()
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
	void InputSystems::ShutDown()
	{
		delete[]m_keystate;
		delete[]m_prevKeystate;
	}
	void InputSystems::Update()
	{
		memcpy(m_prevKeystate, m_keystate, m_numKeys);

		const Uint8* keystate = SDL_GetKeyboardState(nullptr);

		memcpy(m_keystate, keystate, m_numKeys);
	}

	bool InputSystems::GetButtonDown(int id)
	{
		return m_keystate[id];
	}

	bool InputSystems::GetPreviousButtonDown(int id)
	{
		return m_prevKeystate[id];
	}

	InputSystems::eButtonSate InputSystems::GetButtonState(int id)
	{
		InputSystems::eButtonSate state = InputSystems::eButtonSate::IDLE;

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
