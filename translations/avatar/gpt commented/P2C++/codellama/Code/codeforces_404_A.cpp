#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int flag = 0;

    string d1[n];
    string d2[n];
    set<string> rem;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                d1[i] = s[i][j];
            if (i == n - j - 1)
                d2[i] = s[i][j];
            if (i != j && i != n - j - 1)
                rem.insert(s[i][j]);
        }
    }

    if (rem.size() != 1)
        cout << "NO";
    else if (d1 != d2)
        cout << "NO";
    else if (d1.size() != 1)
        cout << "NO";
    else if (d1 == rem)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}

