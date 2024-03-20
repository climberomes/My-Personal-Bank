#pragma once

#include <string>
#include "Constants.h"

class ATMDialog
{
public:
	ATMDialog();
	~ATMDialog();

	//Main Screen to Display
	void OptionsScreen();

	//User Levels
	void SetAdminMode();
	void SetBankerMode();
	void SetCustomerMode();

	//Main ATM Functions
	void ValidateAdminLogon();
	void ValidateBankerLogon();
	void ValidateAccountHolderLogon();
	void ExitBank();

	bool ValidatePasswordFromFile(std::string _Path, std::string _DefaultPass);

private:
	AdminLevel m_enumUserLevel;

	short CheckUserInput();
	void CheckPasswordFile(std::string fileName, std::string _DefaultPass);
	bool CheckPasswordFileEmpty(std::string fileName, std::string& _Response);
	std::string GetPasswordFileData(std::string fileName);
};

