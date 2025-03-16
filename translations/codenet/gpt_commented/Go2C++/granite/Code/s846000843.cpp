
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Initialize input/output handling
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the number of elements
    int n;
    cin >> n;

    // Create a vector to hold the input integers
    vector<int> aa(n);

    // Read each integer and store it in the vector
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }

    // Compute the cumulative sum of the input integers
    vector<int> cumsum(n+1);
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i+1] = cumsum[i] + aa[i];
    }

    // Initialize the answer with a large value
    int ans = 2020202020;

    // Iterate through the cumulative sums to find the minimum difference
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    // Output the final answer
    cout << ans << endl;

    return 0;
}

