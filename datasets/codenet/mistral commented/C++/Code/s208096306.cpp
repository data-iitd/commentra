
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
using ll=long long int; // Define long long int alias 'll' for better readability

// Function to find the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    if (a < b) swap(a, b); // Swap 'a' and 'b' if 'a' is smaller than 'b'

    // Use Euclidean algorithm to find the GCD of 'a' and 'b'
    int r;
    while ((r = a%b) > 0) {
        a = b;
        b = r;
    }

    // Return the GCD of 'a' and 'b'
    return b;
}

int main() {
    int n; // Read the number of integers 'n' from the standard input

    cin >> n; // Read the number of integers 'n' from the standard input and store it in the variable 'n'

    int ans; // Initialize an integer variable 'ans' to store the answer

    cin >> ans; // Read the first integer 'ans' from the standard input and store it in the variable 'ans'

    // Read and process the remaining integers
    for (int i = 1; i < n; ++i) {
        int a; // Initialize an integer variable 'a' to read the next integer from the standard input

        cin >> a; // Read the next integer 'a' from the standard input and store it in the variable 'a'

        // Update the answer by finding the GCD of the current answer and the new integer 'a'
        ans = gcd(ans, a);
    }

    // Print the final answer to the standard output
    cout << ans << endl;

    return 0; // Indicate successful termination of the program
}