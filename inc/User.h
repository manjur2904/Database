#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility> // for pair

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1); // or use any other bit manipulation
    }
};

using Pair = std::pair<std::string, std::string>;
using Matrix = std::vector<std::vector<std::string>>;
using UserTableVsDetail = std::unordered_map<Pair, Matrix, pair_hash>;

class User
{
    std::string UserName;
    std::string Password;
    bool CorrectUser = false;
    int noOfTable = 0;
    //{user,TableName}->vector[][]   vector[0][j]-{columnName1,columnName2,...}  vector[1 to i][0 to vector[0].size()] -{fieldValue1, fieldValue2, fieldValue3,....}
    UserTableVsDetail UserTable;

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