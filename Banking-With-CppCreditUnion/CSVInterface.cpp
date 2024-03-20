#include "CSVInterface.h"
#include "FileNames.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

bool CSVInterface::WriteDataToCSV(std::string _CSVFilePath, AccountUserData _userDataToAdd)
{
    bool fileExists = false;
    bool userDataSaved = false;

    // If file does not exist create it with the default password
    ifstream checkFileExists(_CSVFilePath);
    if (checkFileExists.is_open())
    {
        fileExists = true;
        // File exists, do nothing or handle accordingly
        checkFileExists.close();
    }
    else
    {
        // File doesn't exist, create it
        ofstream writeHeaderData(_CSVFilePath);
        if (writeHeaderData.is_open())
        {
            writeHeaderData << "m_iBankAccountID" << ","
                << "m_sFirstName" << ","
                << "m_sLastName" << ","
                << "m_sDOB" << ","
                << "m_sAccountOpenDate" << ", "
                << "m_enumAccountType" << ","
                << "m_ldBalanceTotal" << ","
                << "m_dInterestRate" << endl;

            writeHeaderData.close();

            fileExists = true;
        }
        else
        {
            cout << "Error: Unable to create file" << endl;
        }
    }

    if (fileExists)
    {
        if(!FindInCSV(_CSVFilePath, _userDataToAdd.m_lBankAccountID, *(new AccountUserData)))
        {
            ofstream writeFileData(_CSVFilePath, std::ios::app);
            if (writeFileData.is_open())
            {
                //add data
                writeFileData << _userDataToAdd.m_lBankAccountID << ","
                    << _userDataToAdd.m_sFirstName << ","
                    << _userDataToAdd.m_sLastName << ","
                    << _userDataToAdd.m_sDOB << ","
                    << _userDataToAdd.m_sAccountOpenDate << ","
                    << _userDataToAdd.m_enumAccountType << ","
                    << (int) (_userDataToAdd.m_dBalanceTotal * 100.0) << ","
                    << _userDataToAdd.m_dInterestRate << endl;

                userDataSaved = true;
            }
            else
            {
                cout << "Error: Unable to create file" << endl;
            }
        }
        else
        {
            cout << "User is already registered in the System!" << endl;
        }
    }

    return userDataSaved;
}

bool CSVInterface::FindInCSV(std::string _CSVFilePath, long _bankAcctID, AccountUserData &_userDataFound)
{
    bool accountFound = false;

    //Open CSV file and iterate through each line until end of file
    std::ifstream CSVFile(_CSVFilePath);
    std::string line;
    while (std::getline(CSVFile, line))
    {
        std::istringstream CSVFileLine(line);
        vector<std::string> strReturnedData(ACCOUNT_USER_DATA_SIZE);

        //Find the account ID first.
        //if account ID is found then gather the rest of the data
        if (std::getline(CSVFileLine, strReturnedData[0], ','))
        {
            long ldReturnedAccountID = std::strtol(strReturnedData[0].c_str(), NULL, 10);

            if (strReturnedData[0].c_str() != nullptr && ldReturnedAccountID == _bankAcctID)
            {
                std::cout << "Account ID: " << _bankAcctID << " is found!" << '\n';

                std::getline(CSVFileLine, strReturnedData[1], ',');
                std::getline(CSVFileLine, strReturnedData[2], ',');
                std::getline(CSVFileLine, strReturnedData[3], ',');
                std::getline(CSVFileLine, strReturnedData[4], ',');
                std::getline(CSVFileLine, strReturnedData[5], ',');
                std::getline(CSVFileLine, strReturnedData[6], ',');
                std::getline(CSVFileLine, strReturnedData[7], ',');

                AccountUserData userDataFound;
                userDataFound.m_lBankAccountID = ldReturnedAccountID;
                userDataFound.m_sFirstName = strReturnedData[1];
                userDataFound.m_sLastName = strReturnedData[2];
                userDataFound.m_sDOB = strReturnedData[3];
                userDataFound.m_sAccountOpenDate = strReturnedData[4];
                userDataFound.m_enumAccountType = (AccountType) (stoi(strReturnedData[4]));
                userDataFound.m_dBalanceTotal = std::strtod(strReturnedData[6].c_str(), NULL) / 100.0;
                userDataFound.m_dInterestRate = std::strtod(strReturnedData[7].c_str(), NULL);

                _userDataFound = userDataFound;
                accountFound = true;
                return accountFound;
                break;
            }
        }
    }

    return accountFound;
}