#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "input.txt";
    std::vector<std::vector<char>> input;
    std::vector<std::vector<char>> inputCopy;
    int rollsAccessed = 0;
    int lastNumOfRollsAccessed = 0;
    bool wasAnyFound = false;
    bool wasZeroFound = false;
    int previousRollsNum = 0;
    
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

    inputCopy = input;

    std::cout << "Table size: " << input.size() << " rows and " << input[0].size() << " columns." <<  std::endl;

    while(wasZeroFound == false)
    {
        input = inputCopy; 

    for(int i = 0; i < input.size(); i++)    //i - row index
    {
        for(int j = 0; j < input[i].size(); j++)    //j - column index
        {
            char c = input[i][j];
            int ctr = 0;
            if(c == '@')
            {
                /// THIS PIECE OF CODE IS FOR MIDDLE OF THE TABLE ///
                if(i > 0 && j > 0 && j < input[i].size() - 1 && i < input.size() - 1)  //middle without edges
                {
                    for(int k = -1; k < 2; k++)     //k - how many adjacent symbols we check
                    {
                        if(input[i -1][j + k] == '@')
                        {
                            ctr++;
                        }
                        if(input[i + 1][j + k] == '@')
                        {
                            ctr++;
                        }

                    }
                        if(input[i][j - 1] == '@')
                        {
                            ctr++;
                        }
                        if(input[i][j + 1] == '@')
                        {
                            ctr++;
                        }

                    if(ctr < 4)
                    {
                        ctr = 0;
                        lastNumOfRollsAccessed++;
                        inputCopy[i][j] = '.';
                        std::cout << "Roll accessed in the middle: " << i << "," << j << std::endl;
                        wasAnyFound = true;
                    }
                }
                /// THIS PIECE OD CODE IS FOR ALL BOUNDARIES ///
                else 
                {
                    /// UPPER ROW WITH CORNERS
                    if(i == 0)
                    {
                        /// LEFT UPPER CORNER ///
                        if(j == 0)
                        {
                            if(input[i][j + 1] == '@')
                            {
                                ctr++;
                            }
                            if(input[i + 1][j] == '@')
                            {
                                ctr++;
                            }
                            if(input[i + 1][j + 1] == '@')
                            {
                                ctr++;
                            }
                        }   
                        /// RIGHT UPPER CORNER ///
                        else if(j == input[i].size() - 1)
                        {
                            if(input[i][j - 1] == '@')
                            {
                                ctr++;
                            }
                            if(input[i + 1][j] == '@')
                            {
                                ctr++;
                            }
                            if(input[i + 1][j - 1] == '@')
                            {
                                ctr++;
                            }
                        }   
                        else
                        {
                             /// THE MIDDLE ///
                
                            for(int k = -1; k < 2; k++)     //k - how many adjacent symbols we check
                            {

                                if(input[1][j + k] == '@')
                                {
                                    ctr++;
                                }

                            }
                            if(input[0][j-1] == '@')
                            {
                                ctr++;
                            }
                            if(input[0][j+1] == '@')
                            {
                                ctr++;
                            }
                        }
                        if(ctr < 4)
                        {
                            lastNumOfRollsAccessed++;
                            inputCopy[i][j] = '.';
                            wasAnyFound = true;
                            std::cout << "Roll accessed in an upper boundary: " << i << "," << j << std::endl;
                        }
                    }
                    /// LOWER ROW WITH CORNERS
                    if(i == input.size() - 1)
                    {
                      /// LEFT LOWER CORNER ///
                        if(j == 0)
                        {
                            if(input[i][j + 1] == '@')
                            {
                                ctr++;
                            }
                            if(input[i - 1][j] == '@')
                            {
                                ctr++;
                            }
                            if(input[i - 1][j + 1] == '@')
                            {
                                ctr++;
                            }
                        }   
                        /// RIGHT LOWER CORNER ///
                        else if(j == input[i].size() - 1)
                        {
                            if(input[i][j - 1] == '@')
                            {
                                ctr++;
                            }
                            if(input[i - 1][j] == '@')
                            {
                                ctr++;
                            }
                            if(input[i - 1][j - 1] == '@')
                            {
                                ctr++;
                            }
                        }   
                        else
                        {
                             /// THE MIDDLE ///
                
                            for(int k = -1; k < 2; k++)     //k - how many adjacent symbols we check
                            {

                                if(input[i - 1][j + k] == '@')
                                {
                                    ctr++;
                                }

                            }
                            if(input[i][j-1] == '@')
                            {
                                ctr++;
                            }
                            if(input[i][j+1] == '@')
                            {
                                ctr++;
                            }
                        }
                        if(ctr < 4)
                        {
                            lastNumOfRollsAccessed++;
                            inputCopy[i][j] = '.';
                            wasAnyFound = true;
                            std::cout << "Roll accessed in a lower boundary: " << i << "," << j << std::endl;
                        }
  
                    }
                    /// LEFT COLUMN WITHOUT CORNERS ///
                    if(j == 0 && i > 0 && i < input.size() - 1)
                    {
                        for(int k = -1; k < 2; k++)
                        {
                            if(input[i + k][j + 1] == '@')
                            {
                                ctr++;
                            }
                        }
                        if(input[i - 1][j] == '@')
                        {
                            ctr++;
                        }
                        if(input[i + 1][j] == '@')
                        {
                            ctr++;
                        }

                        if(ctr < 4)
                        {
                            lastNumOfRollsAccessed++;
                            inputCopy[i][j] = '.';
                            wasAnyFound = true;
                            std::cout << "Roll accessed in a left boundary: " << i << "," << j << std::endl;
                        }
                    }
                    /// RIGHT COLUMN WITHOUT CORNERS ///
                    if(j == input[i].size() - 1 && i > 0 && i < input.size() - 1)
                    {
                        for(int k = -1; k < 2; k++)
                        {
                            if(input[i + k][j - 1] == '@')
                            {
                                ctr++;
                            }
                        }
                        if(input[i - 1][j] == '@')
                        {
                            ctr++;
                        }
                        if(input[i + 1][j] == '@')
                        {
                            ctr++;
                        }

                        if(ctr < 4)
                        {
                            lastNumOfRollsAccessed++;
                            inputCopy[i][j] = '.';
                            wasAnyFound = true;
                            std::cout << "Roll accessed in a right boundary: " << i << "," << j << std::endl;
                        }
                    }
                }

      
                

            }
                //Zrobić żeby iterowało po następnej wersji pętli
                //ZROBIĆ KOPIĘ PĘTLI A NIE ZMIENIAĆ NA ŻYWO -                             input[i][j] = '.';
            rollsAccessed += lastNumOfRollsAccessed;

            ctr = 0;
            lastNumOfRollsAccessed = 0;
        }

    }
            if(previousRollsNum == rollsAccessed)
            {
                wasZeroFound = true;
            }
            else
            {
                previousRollsNum = rollsAccessed;
            }
    }

    std::cout << "Answer: " << rollsAccessed;
}