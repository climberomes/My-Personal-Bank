#pragma once

#include "LevelBanker.h"

class LevelAdmin : public LevelBanker
{
public:
	//Constructor
	LevelAdmin(AccountUserData* _CurrentUser = NULL);
	~LevelAdmin();

	//Set Functions
	void SetAccountID(int _acctID);
	void SetName(std::string _FName = "-1", std::string _LName = "-1");
	void SetDOB(std::string _DOB);
	void SetAccountOpenDate(std::string _OpenDate);
	void SetAccountType(AccountType _AccountType);
	void SetAccountBalance(double _Balance);
	void SetInterestRate(double _Rate);

};

