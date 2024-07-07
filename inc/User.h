#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

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
    void ChangePassword();       // Change password for the user
    void showOptionAfterLogin(); // Show option after login
    void ShowTotalTables();      // Show total tables
    void AddNewTable();          // Add new table
    void DeleteTable();          // Delete table
    void UpdateTable();          // Update  table
    void ShowTableData();        // Show table data
    void ShowTableSchema();      // Show table schema
};