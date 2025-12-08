#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "input.txt";
    std::vector<std::string> nonSerialized;
    std::vector<std::vector<std::string>> input;
    long long answer = 0;
    
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
    
    

    for(int i = 0; i < input[0].size(); i++)    //i - column index
    {
        long long counter;
        char sign;
        if(input[4][i] == "*")
        {
            counter = 1;
            sign = '*';
        }
        else
        {
            counter = 0;
            sign = '+';
        }

        for(int j = 0; j < input.size() - 1; j++)    //j - row index
        {
            if(sign == '*')
            {
                counter *= std::stoll(input[j][i]);
            }
            else
            {
                counter += std::stoll(input[j][i]);
            }
        }

        answer += counter;
    }

    std::cout << "Answer: " << answer;
}