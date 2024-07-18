#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

extern std::unordered_map<std::string, std::string> UserRecords; // <UserName, Password>

void SaveUserInfo();
bool ReadUserInfo();
