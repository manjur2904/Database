#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class User{
    std::string UserName;
    std::string Password;
public:
    User(){}
    void GetUserName();
    void GetPassword();
    bool Signup();
    bool Login();
};