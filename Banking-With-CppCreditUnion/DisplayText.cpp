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

void DisplayText::setTerminalTextColor(int txtColor, int bckColor, int settingVal)
{
	// \033 is the ESC character
	// [ needed for text definition
	// x		x can represent settings
	// ;x		to add more settings
	// m		sets the values?

	if (bckColor == settingVal)
	{
		printf("\033[%dm", txtColor);
	}
	else if (bckColor == -1)
	{
		printf("\033[%d;%dm", txtColor,settingVal);
	}
	else if (settingVal == -1)
	{
		printf("\033[%d;%dm", txtColor, bckColor);
	}
	else
	{
		printf("\033[%d;%d;%dm", txtColor, bckColor, settingVal);
	}
} 

void DisplayText::OutputWelcomeMessage()
{
	//cout << "\033[1;31mWELCOME TO CPP CREDIT UNION\033[0m\n";
	std::cout << "=================================" << std::endl;
	printf("WELCOME TO %s \n", myCompanyName.c_str());
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

void DisplayText::setCompanyName(std::string newCompanyName)
{
	myCompanyName = newCompanyName;
}

std::string DisplayText::getCompanyName()
{
	return myCompanyName;
}

DisplayText::DisplayText(std::string initCompanyName)
{
	//Constructor
	myCompanyName = initCompanyName;
}

DisplayText::~DisplayText()
{
	//Destructor
}