
```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Declare variables for input dimensions and the answer
    int N, M;
    int ans = 0;

    // Read input values for N and M
    cin >> N >> M;

    // Calculate the number of valid positions based on the dimensions
    if (N == 1 && M == 1) {
        // If both dimensions are 1, there's only one position
        ans += 1;
    } else if (1 < N && 1 < M) {
        // If both dimensions are greater than 1, calculate the inner positions
        ans += (N - 2) * (M - 2);
    } else {
        // If one dimension is 1, count the edge positions
        ans += (N * M) - 2;
    }

    // Output the calculated answer
    cout << ans << endl;

    return 0;
}

