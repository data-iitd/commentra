#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int menu[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> menu[i];
        if (menu[i] % 10 == 0)
            menu[i] += 10;
    }
    sort(menu, menu + 5);
    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        ans += ceil(menu[i] / 10.0) * 10;
    }
    cout << ans + menu[0];
    return 0;
}



