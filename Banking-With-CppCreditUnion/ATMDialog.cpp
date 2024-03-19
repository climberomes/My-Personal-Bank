//**************************************
// 
// File Name: ATMDialog.cpp
//
//**************************************
//
// Description: Function used to accept ATM input from customer
//

#include "ATMDialog.h"
#include <iostream>

using namespace std;

ATMDialog::ATMDialog()
{
	m_enumAdminLevel = NONE_LEVEL;
}

ATMDialog::~ATMDialog()
{

}

void ATMDialog::OptionsScreen()
{
	short userSelection = 0;
	bool validResponse = false;

	if (m_enumAdminLevel == NONE_LEVEL)
	{
		cout << "Select Your Options Below" << endl;
		cout << "1 - ADMIN LOGON" << endl;
		cout << "2 - BANKER LOGON" << endl;
		cout << "3 - USER LOGON" << endl;
		cout << "9 - EXIT SYSTEM" << endl;

		do
		{
			cout << endl << "Your Option: ";
			cin >> userSelection;

			if (cin.fail())
			{
				userSelection = 0;
			}

			switch (userSelection)
			{
			case 1:
				ValidateAdminLogon();
				return;
			case 2:
				ValidateBankerLogon();
				return;
			case 3:
				ValidateAccountHolderLogon();
				return;
			case 9:
				ExitBank();
				return;
			default:
				cout << "Invalid Option!" << endl;
				validResponse = false;
				break;
			}

		} while (!validResponse);
	}
	
}

void ATMDialog::ValidateAdminLogon()
{
	cout << "ADMIN LOGON NEEDS CODING!" << endl;
}

void ATMDialog::ValidateBankerLogon()
{
	cout << "BANKER LOGON NEEDS CODING!" << endl;
}

void ATMDialog::ValidateAccountHolderLogon()
{
	cout << "ACCOUNT HOLDER LOGON NEEDS CODING!" << endl;
}

void ATMDialog::ExitBank()
{
	cout << "THANK YOU FOR VISITING CPP CREDIT UNION" << endl;
}