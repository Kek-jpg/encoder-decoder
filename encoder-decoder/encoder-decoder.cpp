
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string encode(string word) // функция шифровки
{
    char alphabetical[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int k = 0;
    for (int i = 0; i < word.size(); i++) // цикл работы шифратора
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

string decode(string word) // функция дешифровки
{
    char alphabetical[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int k = 0;
    for (int i = 0; i < word.size(); i++) // цикл работы дешифратора
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
    while (true) // бесконечный цикл, осуществляющий диалог с пользователем, пока пользователь не захочет выйти
    {
        cout << "Введите 1 для шифровки предолжения\nВведите 2 для расшифровки предложения\nВведите 3 для выхода из приложения\n";

        bool success = false;
        while (!success) // проверка пользовательского ввода на верный тип данных + проверка на целое число
        {
            cin >> theSwitch;
            if (cin.good())
            {
                cout << "Вы ввели значение: " << theSwitch << endl;
                success = true;
            }
            else
            {
                cout << "Значение введено неверно. Повторите ввод:" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
            }
        }
        

        if (theSwitch == 1 || theSwitch == 2 || theSwitch == 3) // проверка ввода на соответствующие программе значения
        {
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
            case 3:
                cout << "До свидания!" << endl;
                exit(0);
            }
        }
        else
        {
            cout << "Вы ввели неверное значение, попробуйте ещё раз" << endl;
        }
    }
}