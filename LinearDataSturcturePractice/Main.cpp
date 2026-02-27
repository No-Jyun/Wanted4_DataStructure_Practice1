#include "Container/CardData.h"

int main()
{
	// 카드 정보 저장 클래스 생성
	CardData cardData;

	// csv 로 부터 파일 읽고 저장
	cardData.ReadCardData();

	// show 를 통해 1번 카드 보여줌

	while (true)
	{
		cardData.ShowCurrentCardData();
				
		// 입력 처리
		// 입력 받을때 까지 대기

		// 오른쪽 방향키 처리

		// 왼쪽 방향키 처리

		// 종료 처리
	}
}