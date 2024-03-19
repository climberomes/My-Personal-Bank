#include <iostream>

#include "Constants.h"
#include "DisplayText.h"

#include "ATMDialog.h"

int main()
{
	//Allows us to start us with Welcome Screen
	DisplayText TextOutput("CPP CREDIT UNION");
	TextOutput.setTerminalTextColor(TEXT::TEXT_COLORS::GREEN, TEXT::BACKGROUND_COLORS::BLUE, TEXT::TEXT_SETTINGS::BRIGHT_ON);
	TextOutput.OutputWelcomeMessage();

	//system("cls");

	ATMDialog OpenBankDialog;
	OpenBankDialog.OptionsScreen();

	TextOutput.ClearTextSettings();
	return 0;
}