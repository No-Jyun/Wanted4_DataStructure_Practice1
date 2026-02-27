#include "Container/CardData.h"
#include "Core/Input.h"

#include <iostream>
#include <Windows.h>

int main()
{
	Input input;

	// 카드 정보 저장 클래스 생성
	CardData cardData;

	// csv 로 부터 파일 읽고 저장
	cardData.ReadCardData("CardData.csv");

	while (true)
	{
		input.ProcessInput();

		// show 를 통해 현재 인덱스에 맞는 카드 보여줌
		cardData.ShowCurrentCardData();
				
		// 입력 처리
		// 오른쪽 방향키 처리 - 인덱스 증가
		if (input.GetKeyDown(VK_RIGHT))
		{
			cardData.GetNextCardData();
		}

		// 왼쪽 방향키 처리 - 인덱스 감소
		if (input.GetKeyDown(VK_LEFT))
		{
			cardData.GetPreviousCardData();
		}

		// ESC 처리 - 종료 처리
		if (input.GetKeyDown(VK_ESCAPE))
		{
			cardData.QuitShowing();
			break;
		}

		// 이전 입력 저장
		input.SavePreviousInputStates();
	}
}