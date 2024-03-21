//**************************************
// 
// File Name: LevelBanker.cpp
//
//**************************************
//
// Description: Class Object Banker to See account info and to add & subtract amount
//				
//				A Banker Level can see what the User Has and Add Subtract
//				At a bank, usually you cant just take money away without talking to someone.
//

#include "LevelBanker.h"

/////////////////////////////
// Constructor
/////////////////////////////
LevelBanker::LevelBanker(AccountUserData* _CurrentUser) : LevelUser(_CurrentUser)
{
}

LevelBanker::~LevelBanker()
{
}

/////////////////////////////
//Operational Functions
/////////////////////////////
void LevelBanker::SubtractAmountToAccount(int _TransactionAmount)
{
	//Amount needs to be positive to work
	if (_TransactionAmount > 0)
	{
		m_UserData->m_dBalanceTotal -= _TransactionAmount;
	}
}

void LevelBanker::AddAmountToAccount(int _TransactionAmount)
{
	//Amount needs to be positive to work
	if (_TransactionAmount > 0)
	{
		m_UserData->m_dBalanceTotal += _TransactionAmount;
	}
}