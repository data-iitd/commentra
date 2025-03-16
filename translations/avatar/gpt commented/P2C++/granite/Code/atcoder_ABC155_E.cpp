
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <numeric>
#include <time.h>

using namespace std;
using ll = long long;

int main() {
    // Read input string
    string s;
    cin >> s;
    int pp = 0;  // Initialize total score
    int na = 0;  // Initialize carry-over value

    // Process the string in reverse order
    for (int i = s.size() - 1; i >= 0; i--) {
        int cc = na + (s[i] - '0');  // Calculate the current value with carry-over
        na = 0;  // Reset carry-over for the next iteration

        // Determine how to update the total score based on the current value
        if (cc <= 4) {
            pp += cc;  // If the value is 4 or less, add it directly to the score
        } else {
            na = 1;  // Set carry-over if the value exceeds 4
            if (i == 0) {
                pp += 1;  // If it's the last digit, add 1 to the score
            }
            pp += 10 - cc;  // Add the difference to the score
        }
    }

    cout << pp << endl;  // Output the final score
    return 0;
}

