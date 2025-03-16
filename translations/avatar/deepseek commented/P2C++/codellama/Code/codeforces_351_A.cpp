#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Extract fractional parts and sort them
    vector<double> arr_frac;
    for (int i = 0; i < n; i++)
        if (arr[i] - floor(arr[i]) != 0)
            arr_frac.push_back(arr[i] - floor(arr[i]));
    sort(arr_frac.begin(), arr_frac.end());

    // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
    int o = 2 * n - arr_frac.size();

    // Sum of the sorted fractional parts
    double arr_sum = 0;
    for (int i = 0; i < arr_frac.size(); i++)
        arr_sum += arr_frac[i];

    // Initialize the result variable to a very large number
    double res = 1e9;

    // Iterate to find the best position
    for (int i = 0; i < n + 1; i++)
    {
        if (i + o >= n)
            res = min(res, abs(i - arr_sum));
    }

    // Print the result with three decimal places
    cout << fixed << setprecision(3) << res << endl;

    return 0;
}

