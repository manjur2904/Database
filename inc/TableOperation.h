#include <Common.h>
class TableOperation
{
    std::vector<std::vector<std::string>> table;
    int row = 0;
    int col = 0;

public:
    TableOperation(std::vector<std::vector<std::string>> &);
    void ShowTableLevelOperation();
    void ShowTableContent();
};