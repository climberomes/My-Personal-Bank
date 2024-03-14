#pragma once

class DisplayText
{
public:

	DisplayText();
	~DisplayText();

	//Member Functions
	void setTerminalTextColor(int settingVal, int txtColor, int bckCol);
	void OutputWelcomeMessage(std::string companyName);
	void ClearTextSettings();
};