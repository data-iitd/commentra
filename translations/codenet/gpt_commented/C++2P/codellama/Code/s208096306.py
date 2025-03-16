#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using ll=long long int;

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using ll=long long int;

// Function to compute the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    // Ensure 'a' is the larger number for the algorithm
    if (a < b) swap(a, b);
    int r;
    // Apply the Euclidean algorithm to find the GCD
    while ((r = a % b) > 0) {
        a = b; // Update 'a' to 'b'
        b = r; // Update 'b' to the remainder
    }
    return b; // Return the GCD
}

int main() {
    int n; // Variable to store the number of integers
    cin >> n; // Read the number of integers from input

    int ans; // Variable to store the current GCD result
    cin >> ans; // Read the first integer and initialize 'ans' with it

    // Loop through the remaining integers to compute the GCD
    for (int i = 1; i < n; ++i) {
        int a; // Variable to store the current integer
        cin >> a; // Read the current integer from input
        ans = gcd(ans, a); // Update 'ans' with the GCD of 'ans' and 'a'
    }

    // Output the final GCD result
    cout << ans << endl;

    return 0; // Indicate that the program ended successfully
}


