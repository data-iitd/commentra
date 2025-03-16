
```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize input/output handling
    auto io = [&]() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return nullptr;
    }();

    // Read the number of heights, target temperature, and actual temperature
    int n;
    double t, a;
    cin >> n >> t >> a;

    // Read the heights as a vector of double
    vector<double> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Initialize minimum difference and index for tracking the closest height
    double minDiff = abs(t - heights[0] * 0.006 - a);
    int minIdx = 0;

    // Iterate through the heights to find the one with the minimum temperature difference
    for (int i = 1; i < n; i++) {
        double diff = abs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i + 1; // Update the index of the closest height
        }
    }

    // Output the 1-based index of the closest height
    cout << minIdx + 1 << endl;

    return 0;
}

