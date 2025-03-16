
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int lst[n];
    for (int i = 0; i < n; i++)
        cin >> lst[i];
    sort(lst, lst + n);
    reverse(lst, lst + n);
    int od = 0;
    for (int i = 0; i < n; i++)
        if (lst[i] % 2 == 1)
            od++;
    int sum = 0;
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (lst[i] % 2 == 0)
            sum += lst[i];
        else
        {
            if (ok || od > 1)
            {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }
    cout << sum << endl;
    return 0;
}

