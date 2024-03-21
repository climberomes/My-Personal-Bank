//**************************************
// 
// File Name: LevelUser.cpp
//
//**************************************
//
// Description: Class Object User to See account info
//				a User Level can only see what they have
//				At a bank, usually you cant just take money away without talking to someone.
//

#include "LevelUser.h"

/////////////////////////////
// Constructor
/////////////////////////////
LevelUser::LevelUser(AccountUserData* _CurrentUser)
{
	if(_CurrentUser == NULL)
	{
		*m_UserData = { -1, "EMPTY", "EMPTY", "mm/dd/yyyy", "mm/dd/yyyy", INVALID, 0.0, 0.0 };
	}
	else
	{
		m_UserData = _CurrentUser;
	}
}

LevelUser::~LevelUser()
{
	delete m_UserData;
}

/////////////////////////////
// Get Functions
/////////////////////////////
AccountUserData LevelUser::GetUserDataObj()
{
	return *m_UserData;
}

long LevelUser::GetBankAccountID()
{
	return m_UserData->m_lBankAccountID;
}

std::string LevelUser::GetName(USHORT _NameType)		//0 for Fullname, 1 for FirstName, 2 for LastName
{
	return m_UserData->m_sLastName + ", " + m_UserData->m_sFirstName;
}

std::string LevelUser::GetDOB()
{
	return m_UserData->m_sDOB;
}

std::string LevelUser::GetAccountOpenDate()
{
	return m_UserData->m_sAccountOpenDate;
}

AccountType LevelUser::GetAccountType()
{
	return m_UserData->m_enumAccountType;
}

double LevelUser::GetBalanceTotal()
{
	return m_UserData->m_dInterestRate;
}

double LevelUser::GetInterestRate()
{
	return m_UserData->m_dInterestRate;
}