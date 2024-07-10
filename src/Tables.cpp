#include <Tables.h>

Tables::Tables(std::string OwnerUsername)
{
    this->OwnerUsername = OwnerUsername;
}

void Tables::showOptionAfterLogin()
{
    int option;
    std::cout << "\nChoose an option:\n";

    std::cout << "1. Show Total Tables Created\n";
    std::cout << "2. Add New  Table\n";
    std::cout << "3. Delete table\n";
    std::cout << "4. Update Table\n";
    std::cout << "5. Show Table Data\n";
    std::cout << "6. Show Table Schema\n";
    std::cout << "\nChoose Option from above: ";
    std::cin >> option;
    switch (option)
    {
    case 1:
        Tables::ShowTotalTables();
        break;
    case 2:
        Tables::AddNewTable();
        break;
    case 3:
        Tables::DeleteTable();
        break;
    case 4:
        Tables::UpdateTable();
        break;
    case 5:
        Tables::ShowTableData();
        break;
    case 6:
        Tables::ShowTableSchema();
        break;
    default:
        std::cout << "Invalid Option!!\n";
        break;
    }
}

void Tables::ShowTotalTables()
{
    std::cout << "\nNumber of tables created: " << noOfTable << std::endl;
    if (noOfTable > 0)
    {
        std::cout << "Tables created are: " << std::endl;
        int cntTable = 0;
        for (auto it : UserTable)
        {
            cntTable++;
            Pair UsernameTablename = it.first;
            std::cout << cntTable << ". " << UsernameTablename.second << std::endl;
        }
    }
    Tables::showOptionAfterLogin();
}

void Tables::AddNewTable()
{
    std::cout << "\n\nEnter the name of the table you want to create: ";
    std::string tableName;
    std::cin >> tableName;
    Matrix table;
    Pair key = std::make_pair(this->OwnerUsername, tableName);
    UserTable[key] = table;
    noOfTable++;
    Tables::showOptionAfterLogin();
}

void Tables::DeleteTable()
{
    std::cout << "DeleteTable function" << std::endl;
}

void Tables::UpdateTable()
{
    std::cout << "UpdateTable function" << std::endl;
}

void Tables::ShowTableData()
{
    std::cout << "ShowTableData function" << std::endl;
}

void Tables::ShowTableSchema()
{
    std::cout << "ShowTableSchema function" << std::endl;
}
