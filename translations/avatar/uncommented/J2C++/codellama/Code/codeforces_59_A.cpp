
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int uppercase = 0, lowercase = 0;
    cin >> word;
    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        if (isupper(ch))
        {
            uppercase++;
        }
        else
        {
            lowercase++;
        }
    }
    if (uppercase > lowercase)
    {
        cout << word.toUpperCase();
    }
    else if (lowercase > uppercase)
    {
        cout << word.toLowerCase();
    }
    else
    {
        cout << word.toLowerCase();
    }
    return 0;
}

