#include <User.h>

int main()
{
    std::cout<<"Are you an exixting user?\n";
    std::cout<<"If Yes, type 1. Either type 0 to Signup\n";
    short userType; // will use enum later
    std::cin>>userType;
    User* user = new User();
    user->GetUserName();
    user->GetPassword();
    if(userType == 1) // Login
    {
        user->Login();
    }
    else if(userType == 0) // SignUp
    {
        user->Signup();
    }
    delete user;
}