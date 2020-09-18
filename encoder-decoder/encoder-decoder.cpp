
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string encode(string word)
{
    char alphabetical[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int k = 0;
    for (int i = 0; i < word.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alphabetical[j])
            {
                k = j + 3;
                switch (j)
                {
                case 23:
                    k = 0;
                    break;
                case 24:
                    k = 1;
                    break;
                case 25:
                    k = 2;
                    break;
                }
                word[i] = alphabetical[k];
                break;
            }
            else if (word[i] == ' ')
            {
                word[i] = ' ';
            }
        }
    }
    return word;
}

string decode(string word)
{
    char alphabetical[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int k = 0;
    for (int i = 0; i < word.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alphabetical[j])
            {
                k = j - 3;
                switch (j)
                {
                case 2:
                    k = 25;
                    break;
                case 1:
                    k = 24;
                    break;
                case 0:
                    k = 23;
                    break;
                }
                word[i] = alphabetical[k];
                break;
            }
            else if (word[i] == ' ')
            {
                word[i] = ' ';
            }
        }
    }
    return word;
}

int main()
{  
    setlocale(LC_ALL, "ru");
    int theSwitch;
    string word;
    while (true)
    {
        cout << "Введите 1 для шифровки предолжения\nВведите 2 для расшифровки предложения\nВведите 3 для выхода из приложения\n";
        cin >> theSwitch;
        switch (theSwitch)
        {
        case 1:
            cout << "Введите предложение для шифровки (на английском языке): ";
            cin.get();
            getline(cin, word);
            cout << "Зашифрованное предложение: " + encode(word) << endl;
            break;
        case 2:
            cout << "Введите предложение для расшифровки (на английском языке): ";
            cin.get();
            getline(cin, word);
            cout << "Расшифрованное предложение: " + decode(word) << endl;
            break;

        }
        if (theSwitch == 3)
            break;
    }
}