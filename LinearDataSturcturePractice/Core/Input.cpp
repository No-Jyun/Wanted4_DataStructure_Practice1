#include "Input.h"
#include <Windows.h>

Input::Input()
{
}

Input::~Input()
{
}

bool Input::GetKeyDown(int keyCode)
{
	return keyStates[keyCode].isKeyDown
		&& !keyStates[keyCode].wasKeyDown;
}

bool Input::GetKeyUp(int keyCode)
{
	return !keyStates[keyCode].isKeyDown
		&& keyStates[keyCode].wasKeyDown;
}

bool Input::GetKey(int keyCode)
{
	return keyStates[keyCode].isKeyDown;
}

void Input::ProcessInput()
{
	// 입력 핸들 얻어오기 & 마우스 입력 활성화 설정.
	static HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	static bool initialized = false;

	// 키보드/마우스 입력을 읽기 위한 변수.
	const int recordCount = 256;

	// 수신한 입력 이벤트를 저장하기 위한 배열.
	INPUT_RECORD records[recordCount] = {};

	// 이번 프레임에 처리한 입력 이벤트 수.
	DWORD eventReadCount = 0;

	// 들어온 입력 이벤트가 있는지 확인.
	if (PeekConsoleInput(inputHandle, records, recordCount, &eventReadCount)
		&& eventReadCount > 0)
	{
		// 이벤트가 있으면, 이벤트를 읽어서 처리.
		if (ReadConsoleInput(inputHandle, records, recordCount, &eventReadCount))
		{
			// 들어온 이벤트 수만큼 루프.
			for (int ix = 0; ix < static_cast<int>(eventReadCount); ++ix)
			{
				INPUT_RECORD& record = records[ix];

				// 이벤트 타입 별로 처리.
				switch (record.EventType)
				{
					// 키 이벤트인 경우.
				case KEY_EVENT:
				{
					// 키 눌림 처리.
					if (record.Event.KeyEvent.bKeyDown)
					{
						keyStates[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = true;
					}

					// 키가 안눌렸을 때.
					else
					{
						keyStates[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = false;
					}
				}
				break;
				}
			}
		}
	}
}

void Input::SavePreviousInputStates()
{
	// 현재 입력 값을 이전 입력 값으로 저장.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].wasKeyDown
			= keyStates[ix].isKeyDown;
	}
}
