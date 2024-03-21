#pragma once

#include "LevelUser.h"

class LevelBanker : public LevelUser
{
public:
	//Constructor
	LevelBanker(AccountUserData* _CurrentUser = NULL);
	~LevelBanker();

	//Operational Functions
	void SubtractAmountToAccount(int _TransactionAmount);
	void AddAmountToAccount(int _TransactionAmount);
};

