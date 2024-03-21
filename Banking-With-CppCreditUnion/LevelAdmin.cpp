//**************************************
// 
// File Name: LevelAdmin.cpp
//
//**************************************
//
// Description: Class Object Admin to create account. and add subtract amount. and view account info
//				
//				An Admin Level can do anything to the account
//				At a bank, usually you cant just take money away without talking to someone.
//				Usually you talk to a manager to set up a new account
//

#include "LevelAdmin.h"

/////////////////////////////
// Constructor
/////////////////////////////
LevelAdmin::LevelAdmin(AccountUserData* _CurrentUser) : LevelBanker(_CurrentUser)
{
}

LevelAdmin::~LevelAdmin()
{
}

/////////////////////////////
//Set Functions
/////////////////////////////
void LevelAdmin::SetAccountID(int _acctID)
{
	m_UserData->m_lBankAccountID = _acctID;
}

void LevelAdmin::SetName(std::string _FName, std::string _LName)
{
	if (_FName.compare("-1") != 0)
	{
		m_UserData->m_sFirstName = _FName;
	}

	if (_FName.compare("-1") != 0)
	{
		m_UserData->m_sLastName = _LName;
	}
}

void LevelAdmin::SetDOB(std::string _DOB)
{
	m_UserData->m_sDOB = _DOB;
}

void LevelAdmin::SetAccountOpenDate(std::string _OpenDate)
{
	m_UserData->m_sAccountOpenDate = _OpenDate;
}

void LevelAdmin::SetAccountType(AccountType _AccountType)
{
	m_UserData->m_enumAccountType = _AccountType;
}

void LevelAdmin::SetAccountBalance(double _Balance)
{
	//Will only be accessible by User-level Bank Operator or Admin
	m_UserData->m_dBalanceTotal = _Balance;
}

void LevelAdmin::SetInterestRate(double _Rate)
{
	//Amount needs to be positive to work
	if (_Rate > 0)
	{
		m_UserData->m_dInterestRate = trunc(_Rate * 100) / 100;
	}
}
