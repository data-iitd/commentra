
#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;
    string a[] = {"10", "100", "1000", "10000", "100000"};
    int new = 0;
    for (int i = 0; i < n.length(); i++)
    {
        new += n[i] - '0';
    }
    if (find(a, a + 5, n) != a + 5)
    {
        cout << 10;
    }
    else
    {
        cout << new;
    }
    return 0;
}

