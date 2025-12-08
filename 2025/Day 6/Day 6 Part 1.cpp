#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "inputEx.txt";
    std::vector<std::string> nonSerialized;
    std::vector<std::vector<std::string>> input;
    int rollsAccessed = 0;
    
    std::ifstream file(path);
    std::string line = "";
    while(getline (file, line))
    {
        nonSerialized.push_back(line);
    }

    for(auto row: nonSerialized)
    {
        bool wasPushed = false;
        std::vector<std::string> rowVec;
        std::string number = "";
        for(auto c: row)
        {
            if(c != ' ')
            {
                wasPushed = false;
                number += c;
            }
            else if (number != "")
            {
                rowVec.push_back(number);
                wasPushed = true;
                number = "";
            }
        }
        if(wasPushed == false)
        {
            rowVec.push_back(number);
            wasPushed = true;
        }
        input.push_back(rowVec);
    }
    
    

    for(int i = 0; i < input.size(); i++)    //i - row index
    {
        for(int j = 0; j < input[i].size(); j++)    //j - column index
        {
            
        }

    }

    std::cout << "Answer: " << rollsAccessed;
}