#pragma once

#include "Constants.h"

class LevelUser
{
public:
	//Constructor
	LevelUser(AccountUserData* _CurrentUser = NULL);
	~LevelUser();

	//Get Functions
	AccountUserData GetUserDataObj();
	long GetBankAccountID();
	std::string GetName(USHORT _NameType = 0);		//0 for Fullname, 1 for FirstName, 2 for LastName
	std::string GetDOB();
	std::string GetAccountOpenDate();
	AccountType GetAccountType();
	double GetBalanceTotal();
	double GetInterestRate();

protected:
	AccountUserData* m_UserData;
};

