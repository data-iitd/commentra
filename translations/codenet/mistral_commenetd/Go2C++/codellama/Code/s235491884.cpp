
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'o')
        {
            n++;
        }
    }

    int result = 700 + n * 100;
    cout << result << endl;

    return 0;
}

