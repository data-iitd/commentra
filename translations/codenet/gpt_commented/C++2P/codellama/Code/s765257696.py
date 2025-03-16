#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>

typedef long long ll; // Define a shorthand for long long type
using namespace std;

const ll MOD = 1000000007LL; // Define a constant for modulo operations

int main() {
    // Optimize input/output operations
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; // Variable to store the number of elements
    cin >> n; // Read the number of elements from input

    int p[n]; // Declare an array to hold the elements
    for (int i = 0; i < n; i++) 
        cin >> p[i]; // Read the elements into the array

    int ans = 0; // Initialize a counter for the number of valid triplets
    // Loop through the array to check for increasing or decreasing triplets
    for (int i = 0; i < n - 2; i++) {
        // Check if the current triplet is strictly decreasing
        if (p[i] > p[i+1] and p[i+1] > p[i+2]):
            ans += 1; // Increment the counter for decreasing triplet

        # Check if the current triplet is strictly increasing
        if (p[i] < p[i+1] and p[i+1] < p[i+2]):
            ans += 1; // Increment the counter for increasing triplet
    }

    print(ans); // Output the total count of valid triplets
    return 0; // Return 0 to indicate successful execution
}

