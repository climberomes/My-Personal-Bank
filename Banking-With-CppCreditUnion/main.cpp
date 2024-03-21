#include <iostream>

#include "Constants.h"
#include "DisplayText.h"

#include "BankDialog.h"

int main()
{
	//Allows us to start us with Welcome Screen
	DisplayText TextOutput("CPP CREDIT UNION");
	TextOutput.setTerminalTextColor(TEXT::TEXT_COLORS::GREEN, TEXT::BACKGROUND_COLORS::BLUE, TEXT::TEXT_SETTINGS::BRIGHT_ON);
	TextOutput.OutputWelcomeMessage();

	//system("cls");

	BankDialog OpenBankDialog;
	OpenBankDialog.OptionsScreen();

	/*
	CSVInterface myCSVInterface;

	AccountUserData m_structCurrentUser = { (long)123456, "BobDa", "Buildah", "12/15/2000", "08/10/2024", SAVINGS, (long double) 12345678.00, 0.05 };
	AccountUserData m_structFindUserData = {};

	m_structCurrentUser.m_dBalanceTotal;

	std::cout << "Creating CSV Stuff" << std::endl;
	myCSVInterface.WriteDataToCSV((DATA_FOLDER + ACCOUNT_DATA_FILE), m_structCurrentUser);



	std::cout << "Account Number To Find: " << std::endl;
	int accountNum;
	std::cin >> accountNum;

	std::cout << "Find Account" << std::endl;
	myCSVInterface.FindInCSV((DATA_FOLDER + ACCOUNT_DATA_FILE), accountNum, m_structFindUserData);

	std::cout << std::to_string(m_structFindUserData.m_dBalanceTotal) << std::endl;
	*/


	TextOutput.ClearTextSettings();
	return 0;
}