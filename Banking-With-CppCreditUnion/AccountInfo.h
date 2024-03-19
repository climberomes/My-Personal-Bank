#pragma once

#include "Constants.h"

class AccountInfo
{
public:
	AccountInfo();
	~AccountInfo();

	//Get Functions
	int GetAccountID();
	std::string GetName(USHORT _NameType = 0);		//0 for Fullname, 1 for FirstName, 2 for LastName
	std::string GetDOB();
	std::string GetAccountOpenDate();
	AccountType GetAccountType();
	long double GetAccountBalance();
	double GetInterestRate();

	//Set Functions
	void SetAccountID(int _acctID);
	void SetName(std::string _FName = "-1", std::string _LName = "-1");
	void SetDOB(std::string _DOB);
	void SetAccountOpenDate(std::string _OpenDate);
	void SetAccountType(AccountType _AccountType);
	void SetAccountBalance(long double _Balance);
	void SetInterestRate(double _Rate);

	//Operational Functions
	void SubtractAmountToAccount(int _TransactionAmount);
	void AddAmountToAccount(int _TransactionAmount);

private:
	AccountUserData m_structCurrentUser;
};

