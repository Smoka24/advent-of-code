#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::string path = "inputEx.txt";
    std::string input = "";
    std::vector<std::string> inputs;
    std::ifstream file(path);
    std::string temp = "";

    while(getline(file, temp, ','))
    {
        inputs.push_back(temp);
    }

    for(auto input: inputs)
    {
        int beginningOfRange = 0;
        int endOfRange = 0;

        for(int i = 0; i < input.size(); i++)
        {
            char c = input[i];
            if(c == '-')
            {
                beginningOfRange = std::stoi(input.substr(0, i));
                endOfRange = std::stoi(input.substr(i+1, input.size()-1));
            }
        }
    }
    //Działa dobre znajdowanie początku i końca rangu, teraz sam algorytm
    //To było na 1/2 roku studiów, ale ja to ja, i tak zrobię własną bruteforce'ową wersję
    //Pora na najbardziej niewydajny algorytm olewający zasady matematyki
    //Bierz każdą liczbę z ranga
    //W niej:
    //Bierz 1. liczbę
    //Szukaj, czy się powtarza
    //Sprawdź, czy liczba ma tylko 2 cyfry, jeśli tak to trafiona
    //Jeśli nie, sprawdź, czy cyfry po trafionych cyfrach są takie same
    //Jeśli nie, szukaj tej samej cyfry ale dalej
    //Jak trafisz, powtórz sprawdzanie po nich, jak nie to bierz nową cyfrę
    //Może coś z tego będzie
}