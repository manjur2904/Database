#include <Common.h>
#include <User.h>
std::unordered_map<std::string, std::string> UserRecords;
int main()
{
    short userType = -1; // will use enum later
    while (userType != 0 && userType != 1)
    {
        std::cout << "Are you an existing user?\n";
        std::cout << "If Yes, type 1. Either type 0 to Signup: ";
        std::cin >> userType;
        if (userType != 0 && userType != 1)
        {
            std::cout << "Please Enter Correct Input!\n";
            ;
        }
    }
    ReadUserInfo();

    User *user = new User();
    user->GetUserName();
    user->GetPassword();
    if (userType == 1) // Login
    {
        user->Login(UserRecords);
    }
    else if (userType == 0) // SignUp
    {
        user->Signup(UserRecords);
        SaveUserInfo();
    }
    delete user;
}

// #include <Common.h>
// #include <User.h>
// #include <unordered_map>
// #include <iostream>
// #include <thread> // For std::this_thread::sleep_for
// #include <chrono> // For std::chrono::seconds

// std::unordered_map<std::string, std::string> UserRecords;

// int main()
// {
//     short userType = -1; // will use enum later
//     while (userType != 0 && userType != 1)
//     {
//         std::cout << "Are you an existing user?\n";
//         std::cout << "If Yes, type 1. Either type 0 to Signup: ";
//         std::cin >> userType;
//         if (userType != 0 && userType != 1)
//         {
//             std::cout << "Please Enter Correct Input!\n";
//         }
//     }

//     ReadUserInfo();

//     User *user = new User();
//     user->GetUserName();
//     user->GetPassword();

//     if (userType == 1) // Login
//     {
//         user->Login(UserRecords);
//     }
//     else if (userType == 0) // SignUp
//     {
//         user->Signup(UserRecords);
//         SaveUserInfo();
//     }

//     delete user;

//     // Keep the program running for a long duration (e.g., ~115 days)
//     std::this_thread::sleep_for(std::chrono::seconds(20));

//     return 0;
// }
