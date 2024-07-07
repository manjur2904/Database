#include <User.h>
#include <Common.h>

void User::GetUserName()
{
    std::cout << "Enter UserName: ";
    std::cin >> this->UserName;
}
void User::GetPassword()
{
    std::cout << "Please enter your Password: ";
    std::cin >> this->Password;
}

bool User::Signup()
{
    if (UserRecords.find(this->UserName) != UserRecords.end())
    {
        std::cout << "UserName: " << this->UserName << " already exist.\n";
        return false;
    }
    else
    {
        UserRecords[this->UserName] = this->Password;
        std::cout << "Congrats!!, You have successfully registered in our Database!!\n";
        return true;
    }
}

bool User::Login()
{
    if (UserRecords.find(this->UserName) != UserRecords.end())
    {
        if (UserRecords[this->UserName] == this->Password)
        {
            std::cout << "User: " << this->UserName << " Login Successfully\n";
            CorrectUser = true;
            return true;
        }
        else
        {
            std::cout << "Wrong Password!!\n";
            return false;
        }
    }
    else
    {
        std::cout << "UserName: " << this->UserName << " Not found!!\n";
        return false;
    }
}

void User::ChangePassword()
{
    std::string username = "";
    std::string password = "";
    std::cout << "Enter UserName: ";
    std::cin >> username;
    std::cout << "Enter the password: ";
    std::cin >> password;
    if (UserRecords.find(username) != UserRecords.end())
    {
        if (UserRecords[username] == password)
        {
            std::cout << "Enter the new password: ";
            std::cin >> password;
            UserRecords[username] = password;
            std::cout << "Password changed successfully!!\n";
        }
        else
        {
            std::cout << "Wrong old Password!!\n";
        }
    }
    else
    {
        std::cout << "UserName: " << username << " Not found!!\n";
    }
}