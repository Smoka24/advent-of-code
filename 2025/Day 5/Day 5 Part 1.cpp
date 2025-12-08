#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "input.txt";
    std::string input = "";
    std::vector<std::string> inputs;
    std::vector<std::pair<long long, long long>> ranges;
    std::ifstream file(path);
    std::string temp = "";
    bool wasNewLine = false;
    long long freshIds = 0;

    while(getline(file, temp))
    {
        inputs.push_back(temp);
    }

    for(auto input: inputs)
    {
        ///Checking half of the table with ranges///
        if(wasNewLine == false)
        {
            if(input == "")
            {
                wasNewLine = true;
            }
            else
            {
            long long beginningOfRange = 0;
            long long endOfRange = 0;
            for(long long i = 0; i < input.size(); i++)
            {
                char c = input[i];
                if(c == '-')
                {
                    try
                    {                                            
                        beginningOfRange = std::stoll(input.substr(0, i));
                        endOfRange = std::stoll(input.substr(i+1, input.size()-1));
                    }
                    catch(const std::exception& e)
                    {
                        std::cout << e.what() << '\n';
                        std::cout << "Some shit happened in paring range: " << input << ": " << input.substr(0, i) << " " << input.substr(i+1, input.size()-1) << "\n";
                    }

                    ranges.push_back(std::make_pair(beginningOfRange, endOfRange));
                }
            }
        }
        }
        else
        {

        
        ///Checking IDS
        long long id = std::stoll(input);
        for (auto range: ranges)
        {
            bool wasFound = false;
            if(id >= range.first && id <= range.second)
            {
                wasFound = true;
                freshIds++;
            }
            if(wasFound) break;
        }
    }

    }

    std::cout << "Answer: " << freshIds;

}