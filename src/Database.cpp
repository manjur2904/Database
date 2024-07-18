#include<Common.h>
#include <User.h>
std::unordered_map<std::string, std::string> UserRecords;
int main()
{
    std::cout<<"Are you an exixting user?\n";
    std::cout<<"If Yes, type 1. Either type 0 to Signup: ";
    short userType; // will use enum later
    std::cin>>userType;

    ReadUserInfo();

    User* user = new User();
    user->GetUserName();
    user->GetPassword();
    if(userType == 1) // Login
    {
        user->Login(UserRecords);
    }
    else if(userType == 0) // SignUp
    {
        user->Signup(UserRecords);
        SaveUserInfo();
    }
    delete user;
}
