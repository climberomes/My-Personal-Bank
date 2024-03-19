#pragma once

#include <string>

#define USHORT unsigned short

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



private:
	USHORT m_usUserLevel;

};

