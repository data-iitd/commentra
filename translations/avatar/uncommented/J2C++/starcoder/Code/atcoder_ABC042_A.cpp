#include <iostream>
using namespace std;
int main()
{
    int x, a, y;
    cin >> x >> a >> y;
    string h = "NO";
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7)
    {
        if (x + y + a == 17)
        {
            h = "YES";
        }
    }
    cout << h << endl;
    return 0;
}
