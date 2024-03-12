#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>

using namespace std;

void decTobin(int wartosc, vector<int>& wynik)
{
    int binaryNum[32];

    int i = 0;
    while(wartosc > 0)
    {
        binaryNum[i] = wartosc % 2;
        wartosc = wartosc / 2;
        i++;
    }

    for(int j = i - 1; j >= 0; j--)
    {
        wynik.push_back(binaryNum[j]);
    }
}

int main()
{
    ifstream in("przed.txt");
    ofstream out("po.txt");

    string tekst{}, word{};

    int wynik1{};

    vector<string> zamiana;
    vector<char> pojedyncze;
    vector<int> binarnie;
    vector<int> wynik;

    cout << "Wpisz tekst ktory chcialbys przekonwertowac na binarny: " << endl;
    getline(cin, tekst);

    stringstream iss(tekst);

    system("cls");

    while(iss >> word)
    {
        zamiana.push_back(word);
    }

    for(const auto& word : zamiana)
    {
        for(int i = 0; i < word.length(); i++)
        {
            pojedyncze.push_back(word[i]);
        }
    }

    for(const auto& x : pojedyncze)
    {
        int wartosc = x;

        cout << wartosc;

        decTobin(wartosc, wynik);
    }

    cout << endl << endl;

    for(const auto& x : wynik)
    {
        cout << x;
    }

    return 0;
}
