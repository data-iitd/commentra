#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of pairs
    int n;
    cin >> n;
    
    // Initialize lists to store the lower and higher values of each pair
    vector<int> low;
    vector<int> high;
    
    // Loop to read each pair and append values to the lists
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        low.push_back(a);
        high.push_back(b);
    }
    
    // Sort the lists
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
    
    // Check if the number of pairs is odd or even
    if (n % 2) {
        // If odd, calculate the range between the middle elements
        cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << endl;
    } else {
        // If even, calculate the average of the middle elements and print the range
        int hh = (high[(n) / 2 - 1] + high[(n) / 2]) / 2;
        int ll = (low[(n) / 2 - 1] + low[(n) / 2]) / 2;
        cout << (hh - ll) * 2 + 1 << endl;
    }
    
    return 0;
}

// 