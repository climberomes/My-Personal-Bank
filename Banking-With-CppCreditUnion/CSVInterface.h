#pragma once
#include "Constants.h"

class CSVInterface
{
public:
	bool WriteDataToCSV(std::string _CSVFilePath, AccountUserData _userDataToAdd);

	bool FindInCSV(std::string _CSVFilePath, long _bankAcctID, AccountUserData& _userDataFound);
};

