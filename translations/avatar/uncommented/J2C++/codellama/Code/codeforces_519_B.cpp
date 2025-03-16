
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        b += x;
    }
    for (int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        c += x;
    }
    int x = a - b, y = b - c;
    cout << x << endl;
    cout << y << endl;
    return 0;
}

