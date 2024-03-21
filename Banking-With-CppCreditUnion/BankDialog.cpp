//**************************************
// 
// File Name: BankDialog.cpp
//
//**************************************
//
// Description: Function used to accept ATM input from customer
//
#include "BankDialog.h"

using namespace std;

//////////////////
//Constructor
//////////////////
BankDialog::BankDialog()
{
	m_enumUserLevel = NONE_LEVEL;
	m_bExitBankDialog = false;

	currentAccountData = new AccountUserData();
	accountAccess_AdminLevel = new LevelAdmin(currentAccountData);
	accountAccess_BankerLevel = new LevelBanker(currentAccountData);
	accountAccess_UserLevel = new LevelUser(currentAccountData);
}

//////////////////
//Destructor
//////////////////
BankDialog::~BankDialog()
{
	delete currentAccountData;
	delete accountAccess_AdminLevel;
	delete accountAccess_BankerLevel;
	delete accountAccess_UserLevel;
}

/**************************************
*Public Member Functions
***************************************/
void BankDialog::OptionsScreen()
{
	while(!m_bExitBankDialog)
	{
		//Display Options screen and process user input
		switch (m_enumUserLevel)
		{
		case NONE_LEVEL:
			UserLevelNoneDialog();
			break;
		case ADMIN_LEVEL:
			UserLevelAdminDialog();
			break;
		case BANKER_LEVEL:
			UserLevelBankerDialog();
			break;
		case USER_LEVEL:
			UserLevelUserDialog();
			break;
		default:
			m_enumUserLevel = NONE_LEVEL;
			break;
		}
	}
}

void BankDialog::ExitBank()
{
	cout << "THANK YOU FOR VISITING CPP CREDIT UNION" << endl;
	m_bExitBankDialog = true;
}


/**************************************
*Private Member Functions
***************************************/

///////////////////////
//Account Verification Functions
///////////////////////
void BankDialog::ValidateAdminLogon()
{
	if (ValidatePasswordFromFile(DATA_FOLDER + ADMIN_PASS_FILE, ADMIN_PASSWORD))
	{
		m_enumUserLevel = ADMIN_LEVEL;
		cout << "Admin Level Enabled" << endl;
	}
	else
	{
		cout << "Admin Level DENIED!" << endl;
	}
}

void BankDialog::ValidateBankerLogon()
{
	if (ValidatePasswordFromFile(DATA_FOLDER + BANKER_PASS_FILE, BANKER_PASSWORD))
	{
		m_enumUserLevel = BANKER_LEVEL;
		cout << "Banker Level Enabled" << endl;
	}
	else
	{
		cout << "Banker Level DENIED!" << endl;
	}
}

void BankDialog::ValidateAccountHolderLogon()
{
	cout << "ACCOUNT HOLDER LOGON NEEDS CODING!" << endl;
}

///////////////////////
//Account Dialog Screens
///////////////////////
void BankDialog::UserLevelNoneDialog()
{
	system("cls");
	bool validResponse = false;

	cout << "Select Your Options Below" << endl;
	cout << "1 - ADMIN LOGON" << endl;
	cout << "2 - BANKER LOGON" << endl;
	cout << "3 - USER LOGON" << endl;
	cout << "9 - EXIT SYSTEM" << endl;

	do
	{
		switch ((short) CheckUserInput())
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
			break;
		default:
			cout << "Invalid Option!" << endl;
			validResponse = false;
			break;
		}
	} while (!validResponse);
}

void BankDialog::UserLevelAdminDialog()
{ 
	system("cls");

	bool validResponse = false;
	int acctNum;

	cout << "Hello ADMIN." << endl;

	do
	{
		cout << "Select Your Options Below" << endl;
		cout << "1 - Create New Account" << endl;
		cout << "2 - Find Account" << endl;
		cout << "9 - Admin Log Off" << endl;

		switch ((short) CheckUserInput())
		{
		case 1:
			accountAccess_AdminLevel = new LevelAdmin();
			CreateAccountDialog();
			validResponse = true;
			break;
		case 2:
			cout << "Insert Account Number To Find" << endl;
			acctNum = CheckUserInput();
			validResponse = interfaceCSV.FindInCSV((DATA_FOLDER + ACCOUNT_DATA_FILE), acctNum, currentAccountData);
			if (!validResponse) { cout << "Account Not Found!" << endl << endl;}
			break;
		case 9:
			m_enumUserLevel = NONE_LEVEL;
			validResponse = true;
			break;
		default:
			cout << "Invalid Option!" << endl;
			validResponse = false;
			break;
		}
	} while (!validResponse);
}

void BankDialog::CreateAccountDialog()
{
	bool validResponse = false;

	do
	{
		cout << "Select Option To Change Account Information" << endl;
		cout << "1 - Set Account ID" << endl;
		cout << "2 - Set Name" << endl;
		cout << "3 - Set DOB" << endl;
		cout << "4 - Set Account Open Date" << endl;
		cout << "5 - Set Account Type" << endl;
		cout << "6 - Set Account Balance" << endl;
		cout << "7 - Set Interest Rate" << endl;
		cout << "9 - Save Account To Database" << endl;

		switch ((short) CheckUserInput())
		{
		case 1:
			validResponse = true;
			break;
		case 2:
			validResponse = true;
			break;
		case 3:
			validResponse = true;
			break;
		case 4:
			validResponse = true;
			break;
		case 5:
			validResponse = true;
			break;
		case 6:
			validResponse = true;
			break;
		case 7:
			validResponse = true;
			break;
		case 9:
			m_enumUserLevel = NONE_LEVEL;
			validResponse = true;
			break;
		default:
			cout << "Invalid Option!" << endl;
			validResponse = false;
			break;
		}
	} while (!validResponse);
}

void BankDialog::UserLevelBankerDialog()
{
	bool validResponse = false;

	if (m_enumUserLevel == BANKER_LEVEL) {cout << "Hello  BANKER." << endl;}

	do
	{
		cout << "Select Your Options Below" << endl;
		cout << "1 - Withdraw From Account" << endl;
		cout << "2 - Deposit To Account" << endl;
		cout << "3 - Account Information Lookup" << endl;
		cout << "9 - Log Off" << endl;

		switch ((short) CheckUserInput())
		{
		case 1:
			validResponse = true;
			break;
		case 2:
			validResponse = true;
			break;
		case 3:
			validResponse = true;
			break;
		case 4:
			validResponse = true;
			break;
		case 5:
			validResponse = true;
			break;
		case 6:
			validResponse = true;
			break;
		case 7:
			validResponse = true;
			break;
		case 8:
			validResponse = true;
			break;
		case 9:
			m_enumUserLevel = NONE_LEVEL;
			validResponse = true;
			break;
		default:
			cout << "Invalid Option!" << endl;
			validResponse = false;
			break;
		}
	} while (!validResponse);
}

void BankDialog::UserLevelUserDialog()
{
	if (m_enumUserLevel == USER_LEVEL) { cout << "Hello  User." << endl;}
}

///////////////////////
//Validation Functions
///////////////////////
int BankDialog::CheckUserInput()
{
	int userInput;
	cout << endl << "Your Input: ";
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
		return -1;
	}
}

void BankDialog::CheckPasswordFile(std::string fileName, std::string _DefaultPass)
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

bool BankDialog::CheckPasswordFileEmpty(std::string fileName, std::string& _Response)
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

std::string BankDialog::GetPasswordFileData(std::string fileName)
{
	// Grab the first line from the file name passed through
	ifstream readFileData(fileName);
	std::string data;
	readFileData >> data;
	readFileData.close();
	return data;
}

bool BankDialog::ValidatePasswordFromFile(std::string _Path, std::string _DefaultPass)
{
	string passFromFile = "";
	CheckPasswordFile(_Path, _DefaultPass);
	CheckPasswordFileEmpty(_Path, passFromFile);


	//Give them 3 attempts then we back out
	bool PassAccepted = false;
	for (int Attempts = 3; Attempts != 0 && PassAccepted != true; Attempts--)
	{
		std::string inputPassword;
		cout << "Please Enter Password: ";
		cin >> inputPassword;
		if (std::strcmp(passFromFile.c_str(), inputPassword.c_str()) != 0)
		{
			cout << "Password Incorrect.\t";
			cout << Attempts - 1 << " Attempts Left" << endl;
		}
		else
		{
			cout << "Password Accepted!" << endl;
			PassAccepted = true;
		}
	}

	return PassAccepted;
}