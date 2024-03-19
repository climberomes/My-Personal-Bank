#pragma once

#include <filesystem>

//Get The Root Parent Directory
const std::string FILE_DIRECTORY = std::filesystem::current_path().parent_path().string() + "\\";
const std::string DATA_FOLDER = FILE_DIRECTORY + "DataFolder\\";

const std::string ADMIN_PASS_FILE = "AdminPass.dat";
const std::string BANKER_PASS_FILE = "BankerPass.dat";

const std::string ADMIN_PASSWORD = "Pass123";