
#include <iostream>

using namespace std;

int main() {
    int n, s, f, t, c = 0;
    
    // Read the number of intervals (n) and the starting point (s)
    cin >> n >> s;
    
    // Iterate over each interval
    for (int i = 0; i < n; i++) {
        // Read the start (f) and end (t) of the interval
        cin >> f >> t;
        
        // Calculate the additional distance that can be covered
        int x = t - (s - f);
        
        // Update the maximum additional distance if the current one is greater
        if (x > c) {
            c = x;
        }
    }
    
    // Output the total distance covered, which is the starting point plus the maximum additional distance
    cout << s + c << endl;
    
    return 0;
}
