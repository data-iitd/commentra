#include <iostream>
using namespace std;
int main()
{
    int tc, tcs;
    cin >> tcs;
    for (tc = 1; tc <= tcs; tc++)
    {
        int a;
        cin >> a;
        cout << (a == 0 ? 1 : 0) << endl;
    }
    return 0;
}
