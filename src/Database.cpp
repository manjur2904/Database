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
