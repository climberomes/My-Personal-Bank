//**************************************
// 
// File Name: AccountInfo.cpp
//
//**************************************
//
// Description: Class Object for anything and everything 
//				related to a single user account.
//

#include "AccountInfo.h"

AccountInfo::AccountInfo()
{
	m_structCurrentUser = { -1, "EMPTY", "EMPTY", "mm/dd/yyyy", "mm/dd/yyyy", INVALID, 0.0, 0.0 };
}

AccountInfo::~AccountInfo()
{
	
}

/////////////////////////////
// Get Functions
/////////////////////////////
int AccountInfo::GetAccountID() 
{
	return m_structCurrentUser.m_lBankAccountID;
}

std::string AccountInfo::GetName(USHORT _NameType)		//0 for Fullname, 1 for FirstName, 2 for LastName
{
	return m_structCurrentUser.m_sLastName + ", " + m_structCurrentUser.m_sFirstName;
}

std::string AccountInfo::GetDOB()
{
	return m_structCurrentUser.m_sDOB;
}

std::string AccountInfo::GetAccountOpenDate()
{
	return m_structCurrentUser.m_sAccountOpenDate;
}

AccountType AccountInfo::GetAccountType()
{
	return m_structCurrentUser.m_enumAccountType;
}

long double AccountInfo::GetAccountBalance()
{
	return m_structCurrentUser.m_dInterestRate;
}

double AccountInfo::GetInterestRate()
{
	return m_structCurrentUser.m_dInterestRate;
}

/////////////////////////////
//Set Functions
/////////////////////////////
void AccountInfo::SetAccountID(int _acctID)
{
	m_structCurrentUser.m_lBankAccountID = _acctID;
}

void AccountInfo::SetName(std::string _FName, std::string _LName)
{
	if (_FName.compare("-1") != 0)
	{
		m_structCurrentUser.m_sFirstName = _FName;
	}
	
	if (_FName.compare("-1") != 0)
	{
		m_structCurrentUser.m_sLastName = _LName;
	}
}

void AccountInfo::SetDOB(std::string _DOB)
{
	m_structCurrentUser.m_sDOB = _DOB;
}

void AccountInfo::SetAccountOpenDate(std::string _OpenDate)
{
	m_structCurrentUser.m_sAccountOpenDate = _OpenDate;
}

void AccountInfo::SetAccountType(AccountType _AccountType)
{
	m_structCurrentUser.m_enumAccountType = _AccountType;
}

void AccountInfo::SetAccountBalance(long double _Balance)
{
	//Will only be accessible by User-level Bank Operator or Admin
	m_structCurrentUser.m_ldBalanceTotal = _Balance;
}

void AccountInfo::SetInterestRate(double _Rate)
{
	//Amount needs to be positive to work
	if (_Rate > 0)
	{
		m_structCurrentUser.m_dInterestRate = trunc(_Rate * 100) / 100;
	}
}

/////////////////////////////
//Operational Functions
/////////////////////////////
void AccountInfo::SubtractAmountToAccount(int _TransactionAmount)
{
	//Amount needs to be positive to work
	if (_TransactionAmount > 0)
	{
		m_structCurrentUser.m_ldBalanceTotal -= _TransactionAmount;
	}
}

void AccountInfo::AddAmountToAccount(int _TransactionAmount)
{
	//Amount needs to be positive to work
	if (_TransactionAmount > 0)
	{
		m_structCurrentUser.m_ldBalanceTotal += _TransactionAmount;
	}
}