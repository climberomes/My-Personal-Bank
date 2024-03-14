#include <iostream>

#include "constants.h"

using namespace std;

void setTerminalTextColor(int settingVal, int txtColor, int bckColor)
{
	// \033 is the ESC character
	// [ needed for text definition
	// x		x can represent settings
	// ;x		to add more settings
	// m		sets the values?
	printf("\033[%d;%d;%dm", settingVal, txtColor, bckColor);
}

void printEntry()
{
	//cout << "\033[1;31mWELCOME TO CPP CREDIT UNION\033[0m\n";
	cout << "=================================" << endl;
	cout << "== WELCOME TO CPP CREDIT UNION ==" << endl;
	cout << "=================================" << endl;
}

void printColorClear()
{
	cout << "\033[0m" << endl;							//Clear out the color settings before we exit
}

int main()
{
	setTerminalTextColor(TEXT::TEXT_SETTINGS::BRIGHT_ON, TEXT::TEXT_COLORS::GREEN, TEXT::BACKGROUND_COLORS::BLUE);
	printEntry();
	

	printColorClear();
	return 0;
}