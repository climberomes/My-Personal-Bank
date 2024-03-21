#include "AccountUserData.h"

AccountUserData::AccountUserData()
{
	InitializeData();
}

AccountUserData::~AccountUserData()
{

}

void AccountUserData::InitializeData()
{
	m_lBankAccountID = -1;
	m_sFirstName = "EMPTY";
	m_sLastName = "EMPTY";
	m_sDOB = "01/31/1900";
	m_sAccountOpenDate = "01/31/1900";
	m_enumAccountType = INVALID;
	m_dBalanceTotal = 0.0;
	m_dInterestRate = 0.0;
}
