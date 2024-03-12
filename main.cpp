#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void decTobin(int wartosc, vector<int>& wynik)
{
    while(wartosc > 0)
    {
        wynik.insert(wynik.begin(), wartosc % 2);
        wartosc = wartosc / 2;
    }
    while(wynik.size() < 8)
    {
        wynik.insert(wynik.begin(), 0);
    }
}

int binTodec(vector<int>& n)
{
    int dec_value = 0;
    int base = 1;

    for(int i = n.size() - 1; i >= 0; i--)
    {
        dec_value += n[i] * base;
        base = base * 2;
    }

    return dec_value;
}

int main()
{
    string tekst{};
    char spacja = ' ';

    vector<char> pojedyncze;
    vector<int> binarnie;

    cout << "Wpisz tekst ktory chcialbys przekonwertowac na binarny: " << endl;
    getline(cin, tekst);

    for(char c : tekst)
    {
        pojedyncze.push_back(c);
    }

    for(const auto& x : pojedyncze)
    {
        int wartosc = x;
        decTobin(wartosc, binarnie);
    }

    cout << endl << endl;

    for(const auto& x : binarnie)
    {
        cout << x;
    }

    cout << endl << endl;

    vector<int> temp;
    for(int i = 0; i < binarnie.size(); i++)
    {
        temp.push_back(binarnie[i]);
        if(temp.size() == 8)
        {
            char dekomp = binTodec(temp);
            cout << dekomp;
            temp.clear();
        }
    }

    cout << endl;

    return 0;
}
