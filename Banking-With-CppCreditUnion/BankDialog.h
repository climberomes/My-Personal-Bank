#pragma once
#include <string>
#include "Constants.h"

#include "LevelAdmin.h"			//To Access Account
#include "CSVInterface.h"		//Act as my Database

class BankDialog
{
public:
	BankDialog();
	~BankDialog();

	//Main Screen to Display
	void OptionsScreen();

	//Leave Bank
	void ExitBank();

//Private Variables
private:
	bool				m_bExitBankDialog;
	AdminLevel			m_enumUserLevel;
	CSVInterface		interfaceCSV;

	AccountUserData*	currentAccountData;
	LevelAdmin*			accountAccess_AdminLevel;
	LevelBanker*		accountAccess_BankerLevel;
	LevelUser*			accountAccess_UserLevel;

//Private Functions
private:
	//Account Verification Functions
	void ValidateAdminLogon();
	void ValidateBankerLogon();
	void ValidateAccountHolderLogon();

	//Account Dialog Screens
	void UserLevelNoneDialog();
	void UserLevelAdminDialog();
	void UserLevelBankerDialog();
	void UserLevelUserDialog();

	void CreateAccountDialog();

	//Validation Functions
	int CheckUserInput();
	void CheckPasswordFile(std::string fileName, std::string _DefaultPass);
	bool CheckPasswordFileEmpty(std::string fileName, std::string& _Response);
	std::string GetPasswordFileData(std::string fileName);

	bool ValidatePasswordFromFile(std::string _Path, std::string _DefaultPass);
};

