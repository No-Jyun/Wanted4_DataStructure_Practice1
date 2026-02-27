#pragma once

#include "Vector.h"
#include <string>

class CardData
{
public:
	CardData();
	~CardData();

	void ReadCardData(const char* filename);

	void ShowCurrentCardData();

	void GetNextCardData();

	void GetPreviousCardData();

	void QuitShowing();

private:
	int cardSize = 0;
	int curCardIndex = 0;

	Vector<int> cardId;
	Vector<std::string> cardName;
	Vector<std::string> cardType;
	Vector<int> cardCost;
	Vector<int> cardRarity;
};

