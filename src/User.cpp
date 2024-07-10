#include <User.h>
#include <Common.h>
#include <Tables.h>

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
        Tables *UserTb = new Tables(this->UserName);
        UserTb->showOptionAfterLogin();
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
            Tables *UserTb = new Tables(this->UserName);
            UserTb->showOptionAfterLogin();
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

// void User::showOptionAfterLogin()
// {
//     int option;
//     std::cout << "\nChoose an option:\n";

//     std::cout << "1. Show Total Tables Created\n";
//     std::cout << "2. Add New  Table\n";
//     std::cout << "3. Delete table\n";
//     std::cout << "4. Update Table\n";
//     std::cout << "5. Show Table Data\n";
//     std::cout << "6. Show Table Schema\n";
//     std::cout << "\nChoose Option from above: ";
//     std::cin >> option;
//     switch (option)
//     {
//     case 1:
//         User::ShowTotalTables();
//         break;
//     case 2:
//         User::AddNewTable();
//         break;
//     case 3:
//         User::DeleteTable();
//         break;
//     case 4:
//         User::UpdateTable();
//         break;
//     case 5:
//         User::ShowTableData();
//         break;
//     case 6:
//         User::ShowTableSchema();
//         break;
//     default:
//         std::cout << "Invalid Option!!\n";
//         break;
//     }
// }

// void User::ShowTotalTables()
// {
//     std::cout << "\nNumber of tables created: " << noOfTable << std::endl;
//     if (noOfTable > 0)
//     {
//         std::cout << "Tables created are: " << std::endl;
//         int cntTable = 0;
//         for (auto it : UserTable)
//         {
//             cntTable++;
//             Pair UsernameTablename = it.first;
//             std::cout << cntTable << ". " << UsernameTablename.second << std::endl;
//         }
//     }
//     User::showOptionAfterLogin();
// }

// void User::AddNewTable()
// {
//     std::cout << "\n\nEnter the name of the table you want to create: ";
//     std::string tableName;
//     std::cin >> tableName;
//     Matrix table;
//     Pair key = std::make_pair(this->UserName, tableName);
//     UserTable[key] = table;
//     noOfTable++;
//     User::showOptionAfterLogin();
// }

// void User::DeleteTable()
// {
//     std::cout << "DeleteTable function" << std::endl;
// }

// void User::UpdateTable()
// {
//     std::cout << "UpdateTable function" << std::endl;
// }

// void User::ShowTableData()
// {
//     std::cout << "ShowTableData function" << std::endl;
// }

// void User::ShowTableSchema()
// {
//     std::cout << "ShowTableSchema function" << std::endl;
// }
