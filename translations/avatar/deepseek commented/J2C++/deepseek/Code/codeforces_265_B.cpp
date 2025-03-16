#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize ans with the value of the first element plus 1
    int ans = arr[0] + 1;

    // Iterate through the array and update ans
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Print the final value of ans
    cout << ans << endl;

    return 0;
}
