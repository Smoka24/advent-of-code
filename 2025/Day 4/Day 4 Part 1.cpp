#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "inputEx.txt";
    std::vector<std::vector<char>> input;
    int rollsAccessed = 0;
    
    std::ifstream file(path);
    std::string line = "";
    while(getline (file, line))
    {
        std::vector<char> row;

        for(char c: line)
        {
            row.push_back(c);
        }
        input.push_back(row);
    }


    for(int i = 0; i < input.size(); i++)    //i - row index
    {
        for(int j = 0; j < input[i].size(); j++)    //j - column index
        {
            char c = input[i][j];
            int ctr = 0;
            if(c == '@')
            {
                if(i - 1 >= 0 && j - 1 >= 0)
                {
                    for(int k = -1; k < 2; k++)     //k - how many adjacent symbols we check
                    {
                        if(input[i -1][j + k] == '@')
                        {
                            ctr++;
                        }
                    }
                }

                if(ctr < 4)
                {
                    rollsAccessed++;
                }
            }
        }

    }

    std::cout << "Answer: " << rollsAccessed;
}