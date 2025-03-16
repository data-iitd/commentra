#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void resolve() {
    // Read the number of intervals
    int n;
    cin >> n;
    
    // Initialize vectors to store the lower and upper bounds of the intervals
    vector<int> low;
    vector<int> high;
    
    // Read each interval and store the lower and upper bounds
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        low.push_back(a);  // Append the lower bound to the low vector
        high.push_back(b);  // Append the upper bound to the high vector
    }
    
    // Sort the lower and upper bounds
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
    
    // Check if the number of intervals is odd
    if (n % 2) {
        // For odd number of intervals, calculate the range of the median interval
        cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << endl;
    } else {
        // For even number of intervals, calculate the average of the two middle values
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;  // Average of the two middle high values
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;    // Average of the two middle low values
        // Calculate the range and print the result
        cout << int((hh - ll) * 2) + 1 << endl;
    }
}

int main() {
    resolve();
    return 0;
}

