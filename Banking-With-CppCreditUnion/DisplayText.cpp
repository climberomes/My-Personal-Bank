//**************************************
// 
// File Name: DisplayText.cpp
//
//**************************************
//
// Description: Function used to Display Text and enable text output settings
//

#include "DisplayText.h"
#include <iostream>

void DisplayText::setTerminalTextColor(int settingVal, int txtColor, int bckColor)
{
	// \033 is the ESC character
	// [ needed for text definition
	// x		x can represent settings
	// ;x		to add more settings
	// m		sets the values?
	printf("\033[%d;%d;%dm", settingVal, txtColor, bckColor);
}

void DisplayText::OutputWelcomeMessage(std::string companyName = "CPP CREDIT UNION")
{
	//cout << "\033[1;31mWELCOME TO CPP CREDIT UNION\033[0m\n";
	std::cout << "=================================" << std::endl;
	printf("== WELCOME TO %s ==\n", companyName);
	std::cout << "=================================" << std::endl;
}

void DisplayText::ClearTextSettings()
{
	// \033 is the ESC character
	// [ needed for text definition
	// 0		0 resets the values
	// m		sets the values?
	std::cout << "\033[0m" << std::endl;							//Clear out the color settings before we exit
}

DisplayText::DisplayText()
{
	//Constructor
}

DisplayText::~DisplayText()
{
	//Destructor
}