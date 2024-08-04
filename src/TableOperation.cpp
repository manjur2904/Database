#include <TableOperation.h>

TableOperation::TableOperation(std::vector<std::vector<std::string>> &table)
{
    this->table = table;
    this->row = table.size();
    if (this->row > 0)
        this->col = table[0].size();
    // this->ShowTableLevelOperation();
}

void TableOperation::ShowTableLevelOperation()
{
    int option;
    std::cout << "\nChoose an option:\n";

    std::cout << "1. Show Table Content\n";
    std::cout << "2. Add New Row\n";
    std::cout << "3. Delete Row\n";
    std::cout << "4. Update Row\n";
    std::cout << "5. Show Row\n";
    std::cout << "6. Show Specific Column\n";
    std::cout << "7. Show Column\n";
    std::cout << "8. Add Filter\n";
    std::cout << "\nChoose Option from above: ";
    std::cin >> option;
    switch (option)
    {
    case 1:
        this->ShowTableContent();
        break;
    default:
        std::cout << "Invalid Option\n";
        break;
    }
}

void TableOperation::ShowTableContent()
{
    std::cout << "Inside ShowTableContent!\n";
}