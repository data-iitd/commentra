#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int s = (1 + n) * n / 2;
        int t = 1;
        while (t <= n)
        {
            s -= 2 * t;
            t *= 2;
        }
        cout << s << endl;
    }
    return 0;
}