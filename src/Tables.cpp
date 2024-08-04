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
    std::cout << "4. Update Table Name\n";
    std::cout << "5. Show Table Data\n";
    std::cout << "6. Show Table Schema\n";
    std::cout << "7. Choose Table\n";
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
        Tables::UpdateTableName();
        break;
    case 5:
        Tables::ShowTableData();
        break;
    case 6:
        Tables::ShowTableSchema();
        break;
    case 7:
        Tables::SelectTable();
        break;
    default:
        std::cout << "Invalid Option!!\n";
        break;
    }
}

void Tables::SelectTable()
{
    std::cout << "\n Enter the Interested Table Name: ";
    std::string tableName;
    std::cin >> tableName;
    if (UserTable.find(std::make_pair(OwnerUsername, tableName)) != UserTable.end())
    {
        std::cout << "Yes We found it!";
        TableOperation *tblop = new TableOperation(UserTable[std::make_pair(OwnerUsername, tableName)]);
        tblop->ShowTableLevelOperation();
    }
    else
    {
        std::cout << " No Table exits with required name";
        Tables::showOptionAfterLogin();
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
    std::cout << "Enter the table name which you want to delete: ";
    std::string tableName;
    std::cin >> tableName;
    Pair key = std::make_pair(this->OwnerUsername, tableName);
    if (UserTable.find(key) == UserTable.end())
    {
        std::cout << "Table does not exist!!\n";
    }
    else
    {
        UserTable.erase(key);
        noOfTable--;
        std::cout << "Table deleted successfully!!\n";
    }
    Tables::showOptionAfterLogin();
}

void Tables::UpdateTableName()
{
    std::cout << "Enter the table name which you want to update: ";
    std::string tableName;
    std::cin >> tableName;
    Pair key = std::make_pair(this->OwnerUsername, tableName);
    if (UserTable.find(key) == UserTable.end())
    {
        std::cout << "Table does not exist!!\n";
    }
    else
    {
        std::cout << "Enter the new table name: ";
        std::string newTableName;
        std::cin >> newTableName;
        Pair newKey = std::make_pair(this->OwnerUsername, newTableName);
        Matrix table = UserTable[key];
        UserTable.erase(key);
        UserTable[newKey] = table;
        std::cout << "Table name is successfully updated!!" << std::endl;
    }
    this->showOptionAfterLogin();
}

void Tables::ShowTableData()
{
    std::cout << "ShowTableData function" << std::endl;
}

void Tables::ShowTableSchema()
{
    std::cout << "ShowTableSchema function" << std::endl;
}
