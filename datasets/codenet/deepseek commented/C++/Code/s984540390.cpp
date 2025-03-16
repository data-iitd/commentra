#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

// Define constants and variables
ll ans, mx, sum, mn = 1e8, cnt = 1;

int main() {
    // Input the value of h
    ll h;
    cin >> h;

    // Loop to calculate the answer
    while (h != 1) {
        if (h % 2 != 0) {
            h--; // Decrement h if it is odd
        }
        h /= 2; // Divide h by 2
        cnt *= 2; // Double the count
        ans += cnt; // Increment the sum by the current count
    }

    // Output the final result
    cout << ans + 1 << endl;
}
