
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    int a = 0, b = 0, c = 0;
    int x, y;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a += temp;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        cin >> temp;
        b += temp;
    }

    for (int i = 0; i < n - 2; i++)
    {
        int temp;
        cin >> temp;
        c += temp;
    }

    x = a - b;
    y = b - c;

    cout << x << endl;
    cout << y << endl;

    return 0;
}

