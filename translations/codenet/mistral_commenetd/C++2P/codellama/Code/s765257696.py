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

#define ll long long
#define MOD 1000000007LL

int main() {
    // Synchronize the input and output streams with stdio
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Read an integer n from the standard input
    int n;
    cin >> n;

    // Allocate an array p of size n to store the input integers
    int p[n];

    // Initialize the variable ans to 0
    int ans = 0;

    // Iterate through the array p from index 0 to n-3
    for (int i = 0; i < n - 2; i++) {
        // Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
        if (p[i] < p[i+1] and p[i+1] < p[i+2]):
            // Increment the ans variable if both conditions are true
            ans += 1;

        # Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
        if (p[i] > p[i+1] and p[i+1] > p[i+2]):
            // Increment the ans variable if both conditions are true
            ans += 1;

    # Print the value of ans to the standard output
    print(ans)

    # Return 0 from the main function to indicate successful execution
    return 0;
}

