
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char alphabetical[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
   
    string word = "soldier Zalu";
    cout << word << endl;
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
    cout << word << endl;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int s = 0;
    for (int i = 0; i < word.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alphabetical[j])
            {
                s = j - 3;
                switch (j)
                {
                case 2:
                    s = 25;
                    break;
                case 1:
                    s = 24;
                    break;
                case 0:
                    s = 23;
                    break;
                }
                word[i] = alphabetical[s];
                break;
            }
            else if (word[i] == ' ')
            {
                word[i] = ' ';
            }
        }
    }
    cout << word << endl;
    string result;
}
