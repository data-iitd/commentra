#include <iostream>
#include <string>
using namespace std;
int main()
{
    string word;
    cin >> word;
    int uppercase = 0, lowercase = 0;
    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        if (isupper(ch))
            uppercase++;
        else
            lowercase++;
    }
    if (uppercase > lowercase)
        cout << word.upper();
    else if (lowercase > uppercase)
        cout << word.lower();
    else
        cout << word.lower();
    return 0;
}
