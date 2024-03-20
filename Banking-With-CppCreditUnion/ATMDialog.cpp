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
	bool validResponse = false;
	bool exitBank = false;

	if (m_enumUserLevel == NONE_LEVEL)
	{
		cout << "Select Your Options Below" << endl;
		cout << "1 - ADMIN LOGON" << endl;
		cout << "2 - BANKER LOGON" << endl;
		cout << "3 - USER LOGON" << endl;
		cout << "9 - EXIT SYSTEM" << endl;

		do
		{
			switch (CheckUserInput())
			{
			case 1:
				ValidateAdminLogon();
				validResponse = true;
				break;
			case 2:
				ValidateBankerLogon();
				validResponse = true;
				break;
			case 3:
				ValidateAccountHolderLogon();
				validResponse = true;
				break;
			case 9:
				ExitBank();
				validResponse = true;
				exitBank = true;
				break;
			default:
				cout << "Invalid Option!" << endl;
				validResponse = false;
				break;
			}

		} while (!exitBank);
	}
	
}

void ATMDialog::ValidateAdminLogon()
{
	if (ValidatePasswordFromFile(ADMIN_PASS_FILE, ADMIN_PASSWORD))
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
	if (ValidatePasswordFromFile(BANKER_PASS_FILE, BANKER_PASSWORD))
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

bool ATMDialog::ValidatePasswordFromFile(std::string _Path, std::string _DefaultPass)
{
	string passFromFile = "";
	CheckPasswordFile(_Path, _DefaultPass);
	CheckPasswordFileEmpty(_Path, passFromFile);
	

	//Give them 3 attempts then we back out
	bool PassAccepted = false;
	for(int Attempts = 3; Attempts != 0 && PassAccepted != true; Attempts--)
	{
		std::string inputPassword;
		cout << "Please Enter Password: ";
		cin >> inputPassword;
		if (std::strcmp(passFromFile.c_str(), inputPassword.c_str()) != 0)
		{
			cout << "Password Incorrect.\t";
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

short ATMDialog::CheckUserInput()
{
	short userInput;
	cout << endl << "Your Option: ";
	cin >> userInput;

	if (cin.good())
	{
		return userInput;
	}
	else
	{
		//something went wrong, we reset the buffer's state to good
		cin.clear();
		//and empty it
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return 0;
	}
}

void ATMDialog::CheckPasswordFile(std::string fileName, std::string _DefaultPass)
{
	// If file does not exist create it with the default password
	ifstream checkFileExists(fileName);
	if (checkFileExists.is_open())
	{
		// File exists, do nothing or handle accordingly
		checkFileExists.close();
	}
	else
	{
		// File doesn't exist, create it
		ofstream writeFileData(fileName);
		if (writeFileData.is_open())
		{
			writeFileData << _DefaultPass << endl;
			cout << "Credentials Not Setup Default Password Created" << endl;
			writeFileData.close();
		}
		else
		{
			cout << "Error: Unable to create file";
		}
	}
}

bool ATMDialog::CheckPasswordFileEmpty(std::string fileName, std::string& _Response)
{
	//Fetch the Password from the file
	std::string passFromFile = GetPasswordFileData(fileName);

	//Verify password is valid (not empty)
	if (passFromFile.empty())
	{
		cout << "Password File Empty. Unable to LogOn" << endl;

		if (std::remove(fileName.c_str()) == 0)
		{
			cout << "File '" << fileName << "' successfully deleted." << endl;
		}
		else
		{
			cout << "Error deleting file '" << fileName << "'." << endl;
		}

		return false;
	}
	else
	{
		//if valid send it back
		_Response = passFromFile;
		return true;
	}
}

std::string ATMDialog::GetPasswordFileData(std::string fileName)
{
	// Grab the first line from the file name passed through
	ifstream readFileData(fileName);
	std::string data;
	readFileData >> data;
	readFileData.close();
	return data;
}