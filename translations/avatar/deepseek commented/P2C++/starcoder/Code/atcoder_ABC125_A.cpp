
#include <iostream>
using namespace std;
int main()
{
    int a, b, t, cookie = 0, time = 0;
    cin >> a >> b >> t;
    while (time <= t + 0.5)
    {
        cookie += b;
        time += a;
    }
    cout << cookie;
    return 0;
}
