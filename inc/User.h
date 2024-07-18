#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class User{
    std::string UserName;
    std::string Password;
    bool CorrectUser = false;

public:
    User(){}
    void GetUserName();
    void GetPassword();
    bool Signup(std::unordered_map<std::string, std::string>& UserRecords);
    bool Login(std::unordered_map<std::string, std::string>& UserRecords);
    void ChangePassword(std::unordered_map<std::string, std::string>& UserRecords); // Change password for the user
};
