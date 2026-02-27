#pragma once

#include "Vector.h"
#include <string>

struct Card
{
	int id;
	std::string name;
	std::string type;
	int cost;
	int rarity;
};

class CardData
{
public:
	CardData();
	~CardData();

	void ReadCardData(std::string filename);

	void ShowCurrentCardData();

	void GetNextCardData();

	void GetPreviousCardData();

	void QuitShowing();

private:
	int cardSize = 0;
	int curCardIndex = 0;
	int exCardIndex = -1;

	Vector<Card> data;

	//Vector<int> cardId;
	//Vector<std::string> cardName;
	//Vector<std::string> cardType;
	//Vector<int> cardCost;
	//Vector<int> cardRarity;
};

