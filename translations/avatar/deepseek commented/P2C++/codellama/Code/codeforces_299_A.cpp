
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[0] % arr[i] == 0)
        {
            ans = arr[0];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

