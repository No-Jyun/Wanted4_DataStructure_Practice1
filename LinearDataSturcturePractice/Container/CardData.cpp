#include "CardData.h"

#include <iostream>
#include <Windows.h>

CardData::CardData()
{
}

CardData::~CardData()
{
}

void CardData::ReadCardData(const char* filename)
{
	std::cout << "저장된 카드 정보를 불러옵니다..\n";

}

void CardData::ShowCurrentCardData()
{
	system("cls");

	static COORD position = { 0,0 };
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);

	std::cout << "현재 카드 ID : " << cardId[curCardIndex] << "\n";
	std::cout << "현재 카드 이름 : " << cardName[curCardIndex] << "\n";
	std::cout << "현재 카드 타입 : " << cardType[curCardIndex] << "\n";
	std::cout << "현재 카드 코스트 : " << cardCost[curCardIndex] << "\n";
	std::cout << "현재 카드 희귀도 : " << cardRarity[curCardIndex] << "\n";

	std::cout << "\n다음 카드 정보를 보시려면 오른쪽 방향키를 누르세요\n";
	std::cout << "이전 카드 정보를 보시려면 왼쪽 방향키를 누르세요\n";
	std::cout << "종료를 원하시면 ESC를 누르세요\n";

	position.X = 0;
	position.Y = 0;
}

void CardData::GetNextCardData()
{
	curCardIndex = (curCardIndex + 1) % cardSize;
}

void CardData::GetPreviousCardData()
{
}

void CardData::QuitShowing()
{
	system("cls");
	std::cout << "프로그램을 종료합니다\n";
}
