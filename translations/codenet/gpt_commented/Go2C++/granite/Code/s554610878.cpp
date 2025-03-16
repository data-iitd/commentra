
```cpp
#include <bits/stdc++.h>
using namespace std;

// Constants for buffer sizes
const int initialBufSize = 10000;
const int maxBufSize = 1000000;

// Global variables for scanner and modulus
string s;
int mod = 1e9 + 7; // Modulus value for calculations

int main() {
    // Array representing the days of the week
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    // Get the input day as a string
    cin >> s;
    
    int index = -1; // Initialize index to -1 to indicate not found
    
    // Search for the input day in the week array
    for (int i = 0; i < week.size(); i++) {
        if (s == week[i]) {
            index = i; // Update index if the day is found
            break;
        }
    }
    
    // Calculate and print the number of days until the next Sunday
    cout << 7 - index << endl;
    
    return 0;
}

