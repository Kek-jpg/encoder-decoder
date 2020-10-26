#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)
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

string return_current_time_and_date() // функция, возвращающая текущую дату и время
{
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}


int main()
{  
    setlocale(LC_ALL, "ru");

    ofstream fout;
    fout.open("log.txt", ofstream::app);
    if (!fout.is_open())
    {
        cout << "Запись в log-файл не ведётся!" << endl; // Проверка на действительность ведения log-файла
    }
    else
    {
        fout << "Программа запущена. Начало записи в log-файл: " << return_current_time_and_date() << endl; // Отметка о старте программы и начале записи в log
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
                    fout << "Пользователь ввёл значение: " << theSwitch << " |Время: " << return_current_time_and_date() << endl; // Логируем ввод пользователя и время
                    success = true;
                }
                else
                {
                    cout << "Значение введено неверно. Повторите ввод:" << endl;
                    fout << "Введено неверное значение: " << theSwitch << " |Время: " << return_current_time_and_date() << endl; // Логируем некорректность ввода и время
                    cin.clear();
                    cin.ignore(32767, '\n');
                }
            }


            if (theSwitch == 1 || theSwitch == 2 || theSwitch == 3) // проверка ввода на соответствующие программе значения
            {
                fout << "Введено верное значение: " << theSwitch <<" |Время: " << return_current_time_and_date() << endl; // Логируем успешность ввода и время
                switch (theSwitch)
                {
                case 1:
                    cout << "Введите предложение для шифровки (на английском языке): ";
                    cin.get();
                    getline(cin, word);
                    cout << "Зашифрованное предложение: " + encode(word) << endl;
                    fout << "Предложение " << word << " успешно зашифровано." << " |Время:" << return_current_time_and_date() << endl; // Логируем шифрование предложения и время
                    break;
                case 2:
                    cout << "Введите предложение для расшифровки (на английском языке): ";
                    cin.get();
                    getline(cin, word);
                    cout << "Расшифрованное предложение: " + decode(word) << endl;
                    fout << "Предложение " << word << " успешно расшифровано." << " |Время:" << return_current_time_and_date() << endl; // Логируем расшифрование предложения и время
                    break;
                case 3:
                    cout << "До свидания!" << endl;
                    fout << "Пользователь выходит из программы." << " |Время:" << return_current_time_and_date() << endl << endl; // Логирование выхода пользователя из программы
                    fout.close(); // Закрытие log-файла
                    exit(0);
                }
            }
            else
            {
                cout << "Вы ввели неверное значение, попробуйте ещё раз" << endl;
                fout << "Введено неверное значение: " << theSwitch << " |Время: " << return_current_time_and_date() << endl; // Логируем некорректность ввода и время
            }

        }
    }
}