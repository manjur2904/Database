#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class User
{
    std::string UserName;
    std::string Password;
    bool CorrectUser = false;

public:
    User() {}
    void GetUserName();
    void GetPassword();
    bool Signup();
    bool Login();
    void ChangePassword(); // Change password for the user
};