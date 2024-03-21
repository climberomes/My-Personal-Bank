#pragma once
#include <string>

// Define a Enumeration for Account Types
enum AccountType {
	INVALID,
	CHECKING,
	SAVINGS,
	CREDIT_CARD,
	PERSONAL_LOAN,
	STUDENT_LOAN
};

class AccountUserData
{
public:
	AccountUserData();
	~AccountUserData();

	void InitializeData();			//Keep the memory address, but set default values

	long			m_lBankAccountID;
	std::string		m_sFirstName;
	std::string		m_sLastName;
	std::string		m_sDOB;
	std::string		m_sAccountOpenDate;
	AccountType		m_enumAccountType;
	double			m_dBalanceTotal;
	double			m_dInterestRate;
};

