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

#include "FileNames.h"

#include <fstream>

using namespace std;

ATMDialog::ATMDialog()
{
	m_enumUserLevel = NONE_LEVEL;
}

ATMDialog::~ATMDialog()
{

}

void ATMDialog::OptionsScreen()
{
	short userSelection = 0;
	bool validResponse = false;

	if (m_enumUserLevel == NONE_LEVEL)
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
				validResponse = false;
				break;
			case 2:
				ValidateBankerLogon();
				validResponse = false;
				break;
			case 3:
				ValidateAccountHolderLogon();
				validResponse = false;
				break;
			case 9:
				ExitBank();
				validResponse = false;
				break;
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
	if (ValidatePasswordFromFile(ADMIN_PASS_FILE))
	{
		m_enumUserLevel = ADMIN_LEVEL;
		cout << "Admin Level Enabled" << endl;
	}
	else
	{
		cout << "Admin Level DENIED!" << endl;
	}
}

void ATMDialog::ValidateBankerLogon()
{
	cout << "BANKER LOGON NEEDS CODING!" << endl;
	if (ValidatePasswordFromFile(BANKER_PASS_FILE))
	{
		m_enumUserLevel = BANKER_LEVEL;
		cout << "Banker Level Enabled" << endl;
	}
	else
	{
		cout << "Banker Level DENIED!" << endl;
	}
}

void ATMDialog::ValidateAccountHolderLogon()
{
	cout << "ACCOUNT HOLDER LOGON NEEDS CODING!" << endl;
}

void ATMDialog::ExitBank()
{
	cout << "THANK YOU FOR VISITING CPP CREDIT UNION" << endl;
}

bool ATMDialog::ValidatePasswordFromFile(std::string _Path)
{
	//File for Writing
	// If file does not exist create it with my default password
	ofstream writeFileData(DATA_FOLDER + _Path);		//outdata is like cin
	if (!writeFileData)
	{
		cout << "Credentials Not Setup" << endl;
		writeFileData.open(DATA_FOLDER + _Path);
		writeFileData << ADMIN_PASSWORD << endl;
		cout << "Default Admin Password Created" << endl;
	}
	writeFileData.close();

	//File for Reading
	// Grab the Password (if they changed it then it wont have the default)
	ifstream readFileData(DATA_FOLDER + _Path);
	std::string data;
	readFileData >> data;
	readFileData.close();

	//Give them 3 attempts then we back out
	bool PassAccepted = false;
	for(int Attempts = 3; Attempts != 0 && PassAccepted != true; Attempts--)
	{
		std::string inputPassword;
		cout << "Please Enter Admin Password: ";
		cin >> inputPassword;
		if (data.compare(inputPassword) != 0)
		{
			cout << "Password Incorrect." << endl;
			cout << Attempts-1 << " Attempts Left" << endl;
		}
		else
		{
			cout << "Password Accepted!" << endl;
			PassAccepted = true;
		}
	}

	return PassAccepted;

}