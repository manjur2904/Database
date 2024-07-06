#include <User.h>
#include <Common.h>

void User::GetUserName()
{
    std::cout<<"Enter UserName: ";
    std::cin>>this->UserName;
}
void User::GetPassword()
{
    std::cout<<"Please enter your Password: ";
    std::cin>>this->Password;
}

bool User::Signup()
{
    if(UserRecords.find(this->UserName) != UserRecords.end())
    {
        std::cout<<"UserName: "<<this->UserName<<" already exist.\n";
        return false;
    }
    else
    {
        UserRecords[this->UserName] = this->Password;
        std::cout<<"Congrats!!, You have successfully registered in our Database!!\n";
        return true;
    }
}

bool User::Login()
{
    if(UserRecords.find(this->UserName) != UserRecords.end())
    {
        if(UserRecords[this->UserName] == this->Password)
        {
            std::cout<<"User: "<<this->UserName<<" Login Successfully\n";
            return true;
        }
        else
        {
            std::cout<<"Wrong Password!!\n";
            return false;
        }
    }
    else
    {
        std::cout<<"UserName: "<<this->UserName<<" Not found!!\n";
        return false;
    }
}