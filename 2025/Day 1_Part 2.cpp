#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int turnNumber(std::string input)
{
    int turnNumber = 0;

    std::string numStr = input.substr(1, input.length() - 1);
    turnNumber = std::atoi(numStr.c_str());

    return turnNumber;
}

int main() 
{
    std::string path = "input1.txt";
    std::vector<std::string> inputs;
    int actualIndex = 50;
    int numberOfZeros = 0;
    bool wasAlreadyZero = false;

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
                int diff = actualIndex;
                while(diff <= -100)
                {
                    diff += 100;
                    numberOfZeros++;
                    wasAlreadyZero = true;
                }
                diff *= -1;
                actualIndex = 100 - diff;
                if(!wasAlreadyZero)
                numberOfZeros++;
            }
        }   
        else
        {
            actualIndex += turns;
        
            if(actualIndex > 99)
            {
                int diff = actualIndex;
                while(diff >= 100)
                {
                    diff -= 100;
                    numberOfZeros++;
                    wasAlreadyZero = true;
                }               
                actualIndex = diff;
                if(!wasAlreadyZero)
                numberOfZeros++;
            }
        }   
        wasAlreadyZero = false;
    }

    std::cout << "Answer: " << numberOfZeros;


}