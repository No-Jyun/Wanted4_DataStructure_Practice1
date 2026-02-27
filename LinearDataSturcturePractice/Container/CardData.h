#pragma once

#include "Vector.h"
#include <string>

struct Card
{
	int id = 0;
	std::string name = "";
	std::string type = "";
	int cost = 0;
	int rarity = 0;
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
};

