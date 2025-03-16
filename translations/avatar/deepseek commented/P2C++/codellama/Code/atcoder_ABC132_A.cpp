
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    string S;
    cin >> S;

    map<char, int> c;
    for (int i = 0; i < S.length(); i++)
    {
        c[S[i]]++;
    }

    set<char> Sa;
    for (int i = 0; i < S.length(); i++)
    {
        Sa.insert(S[i]);
    }

    if (Sa.size() != 2)
    {
        cout << "No" << endl;
        return 0;
    }

    for (auto i : Sa)
    {
        if (c[i] != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}

