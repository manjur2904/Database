#include <Common.h>

// std::unordered_map<std::string, std::string> UserRecords; // <UserName, Password>


void SaveUserInfo()
{
    json j = json::array();

    for(auto user : UserRecords)
    {
        json userInfo;
        userInfo["UserName"] = user.first;
        userInfo["Password"] = user.second;
        j.push_back(userInfo);
    }

    std::ofstream file("datas/UserInfo.json");
    file << j.dump(4);
}

bool ReadUserInfo()
{
    // std::cout<<"Reading user info\n";
    try
    {
        json j;
        std::ifstream infile("datas/UserInfo.json");

        if(infile.is_open())
        {
            if(infile.peek() == std::ifstream::traits_type::eof())
            {
                // std::cout<<"File is empty\n";
                infile.close();
                return true;
            }
            infile >> j;
            infile.close();
        }
        else
        {
            std::cerr<<"Could not open the datas/UserInfo.json file\n";
            return false;
        }
        
        for(const auto& user : j)
        {
            UserRecords[user["UserName"]] = user["Password"];
            // std::cout<<"UserName: "<<user["UserName"]<<", Password: "<<user["Password"]<<std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}