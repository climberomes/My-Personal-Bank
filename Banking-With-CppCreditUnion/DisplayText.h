#pragma once

#include <string>

class DisplayText
{
public:

	DisplayText(std::string initCompanyName);
	~DisplayText();

	//Member Functions
	void setTerminalTextColor(int txtColor, int bckCol=-1, int settingVal=-1);
	void OutputWelcomeMessage();
	void ClearTextSettings();

	void setCompanyName(std::string newCompanyName);
	std::string getCompanyName();

private:
	std::string myCompanyName;
};