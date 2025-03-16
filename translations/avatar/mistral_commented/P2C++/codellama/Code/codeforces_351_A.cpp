#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<float> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<float> arr_filtered;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - floor(arr[i]) != 0)
        {
            arr_filtered.push_back(arr[i]);
        }
    }

    int o = 2 * n - arr_filtered.size();

    float arr_sum = 0;
    for (int i = 0; i < arr_filtered.size(); i++)
    {
        arr_sum += arr_filtered[i];
    }

    float res = 1e9;
    for (int i = 0; i < n + 1; i++)
    {
        if (i + o >= n)
        {
            res = min(res, abs(i - arr_sum));
        }
    }

    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

