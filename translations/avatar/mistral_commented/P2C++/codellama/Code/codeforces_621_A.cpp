#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> lst(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lst[i];
    }

    sort(lst.begin(), lst.end());
    reverse(lst.begin(), lst.end());

    int od = 0;
    for (int i : lst)
    {
        if (i & 1)
        {
            od++;
        }
    }

    int sum = 0;
    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        if (lst[i] % 2 == 0)
        {
            sum += lst[i];
        }
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

