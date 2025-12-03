#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "input.txt";
    std::vector<std::string> inputs;
    int actualIndex = 50;
    int numberOfZeros = 0;

    std::ifstream file(path);
    std::string line = "";
    while(getline (file, line))
    {
        inputs.push_back(line);
    }

    int sum = 0;

    for(auto input: inputs)
    {
        std::vector<int> digits;
        for(int i = 0; i < input.length(); i++)
        {
            char c = input[i];
            digits.push_back((int)c - '0');
        }

        int maxInLine = 0;
        int indexOfMax = 0;
        for(int i = 0; i < digits.size(); i++)
        {
            int digit = digits[i];
            if(digit > maxInLine)
            {
                maxInLine = digit;
                indexOfMax = i;
            }
        }

        if(indexOfMax == digits.size() - 1)
        { 
            maxInLine = 0;
            indexOfMax = 0;

            for(int i = 0; i < digits.size() - 1; i++)
            {
                int digit = digits[i];
                if(digit > maxInLine)
                {
                    maxInLine = digit;
                    indexOfMax = i;
                }
            }
                        
        }

        int secondMax = 0;
        for(int i = indexOfMax + 1; i < digits.size(); i++)
        {
            int secondDigit = digits[i];
            if(secondDigit > secondMax)
            {
                secondMax = secondDigit;
            }
        }

        int number = maxInLine * 10 + secondMax;
        sum += number;
    }
    std::cout << "Sum: " << sum << std::endl;

    //Szukaj od największej cyfry 9 -> 1
    //Sprawdź, czy nie jest na końcu
    //Jeśli nie, szukaj największej cyfry po niej
}