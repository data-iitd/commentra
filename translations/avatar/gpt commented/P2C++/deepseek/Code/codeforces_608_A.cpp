#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of intervals (n) and the starting point (s)
    int n, s;
    cin >> n >> s;

    // Initialize a variable to keep track of the maximum additional distance (c)
    int c = 0;

    // Iterate over each interval
    for (int i = 0; i < n; ++i) {
        // Read the start (f) and end (t) of the interval
        int f, t;
        cin >> f >> t;
        
        // Calculate the additional distance that can be covered
        int x = t - (s - f);
        
        // Update the maximum additional distance if the current one is greater
        if (x > c) {
            c = x;
        }
    }

    // Output the total distance covered, which is the starting point plus the maximum additional distance
    cout << s + c << '\n';

    return 0;
}
