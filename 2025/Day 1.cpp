#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int turnNumber(std::string input)
{
    int turnNumber = 0;

    if(input.length() == 2)
    {
        std::string numStr = input.substr(1,1);
        turnNumber = std::atoi(numStr.c_str());
    }
    else
    {
        std::string numStr = input.substr(1,2);
        turnNumber = std::atoi(numStr.c_str());
    }

    return turnNumber;
}

int main() 
{
    std::string path = "input1.txt";
    std::vector<std::string> inputs;
    int actualIndex = 50;
    int numberOfZeros = 0;

    std::ifstream file(path);
    std::string line = "";
    while(getline (file, line))
    {
        inputs.push_back(line);
    }

    for(auto input: inputs)
    {
        int turns = turnNumber(input);


        if(input[0] == 'L')
        {
            actualIndex -= turns;
        
            if(actualIndex < 0)
            {
                int diff = actualIndex * -1;
                actualIndex = 100 - diff;
            }
        }
        else
        {
            actualIndex += turns;
        
            if(actualIndex > 99)
            {
                int diff = actualIndex - 99;
                actualIndex = -1 + diff;
            }
        }
        if(actualIndex == 0)
        {
            numberOfZeros++;
        }
    }

    std::cout << "Answer: " << numberOfZeros;


}