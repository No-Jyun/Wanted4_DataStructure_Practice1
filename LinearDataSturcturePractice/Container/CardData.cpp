#include "CardData.h"

#include <iostream>
#include <fstream>
#include <Windows.h>

CardData::CardData()
{
}

CardData::~CardData()
{
}

void CardData::ReadCardData(std::string filename)
{
	std::cout << "저장된 카드 정보를 불러옵니다..\n";

	// 파일 로드
	std::string path = "../Resources/" + filename;
	std::ifstream file(path);

	// 예외 처리
	if (!file.is_open())
	{
		std::cout << "파일 로드 오류..\n";
		__debugbreak();
	}

	std::string line;

	// 첫 줄은 아무 처리도 하지 않고 넘어감
	getline(file, line);

	// 한 줄씩 읽기
	while (getline(file, line)) 
	{
		// 개행 문자 처리
		size_t rPos = line.find('\r');
		if (rPos != std::string::npos) 
		{
			line.erase(rPos);
		}

		// 빈 줄이면 스킵
		if (line.empty()) 
		{
			continue;
		}

		// CSV 파싱 (쉼표 기준 분리)
		Vector<std::string> row;
		size_t start = 0;
		size_t end = 0;

		// start 인덱스부터 ',' 찾기
		while ((end = line.find(',', start)) != std::string::npos) 
		{
			row.Push(line.substr(start, end - start));
			start = end + 1;
		}

		// 마지막 데이터 추가
		row.Push(line.substr(start));

		// 카드 정보 구조체 생성
		Card nowCard;
		nowCard.id = stoi(row[0]);
		nowCard.name = row[1];
		nowCard.type = row[2];
		nowCard.cost = stoi(row[3]);
		nowCard.rarity = stoi(row[4]);

		// 배열에 저장
		data.Push(nowCard);

		// 배열 크기 증가
		cardSize++;
	}

	// 파일 닫기
	file.close();

	std::cout << "카드 정보를 전부 저장했습니다.\n";

	DWORD delay = static_cast<DWORD>(1.0f * 1000);
	Sleep(delay);
}

void CardData::ShowCurrentCardData()
{
	if (curCardIndex == exCardIndex)
	{
		return;
	}
	exCardIndex = curCardIndex;

	system("cls");

	static COORD position = { 0,0 };
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);

	std::cout << "현재 카드 ID : " << data[curCardIndex].id << "\n";
	std::cout << "현재 카드 이름 : " << data[curCardIndex].name << "\n";
	std::cout << "현재 카드 타입 : " << data[curCardIndex].type << "\n";
	std::cout << "현재 카드 코스트 : " << data[curCardIndex].cost << "\n";
	std::cout << "현재 카드 희귀도 : " << data[curCardIndex].rarity << "\n";

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
	--curCardIndex;

	if (curCardIndex < 0)
	{
		curCardIndex = cardSize - 1;
	}
}

void CardData::QuitShowing()
{
	system("cls");
	std::cout << "프로그램을 종료합니다\n";
}
