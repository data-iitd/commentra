#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    getline(cin, a);
    a.replace(a.find(","), 1, " ");
    cout << a;
    return 0;
}

