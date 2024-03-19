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

	bool ValidatePasswordFromFile(std::string _Path);

private:
	AdminLevel m_enumUserLevel;

};

