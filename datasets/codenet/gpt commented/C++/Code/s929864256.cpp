#include <iostream>    // Include the input-output stream library
#include <algorithm>   // Include the algorithm library for max function
#include <vector>      // Include the vector library (not used in this code)
#include <map>         // Include the map library (not used in this code)
#include <set>         // Include the set library (not used in this code)
#include <string>      // Include the string library (not used in this code)
#include <queue>       // Include the queue library (not used in this code)
#include <list>        // Include the list library (not used in this code)
#include <cmath>       // Include the cmath library (not used in this code)
#include <stack>       // Include the stack library (not used in this code)
#include <iomanip>     // Include the iomanip library for formatting output

using namespace std;    // Use the standard namespace
typedef long long ll;  // Define a shorthand for long long type
using Pll = pair<ll,ll>; // Define a shorthand for a pair of long long integers

const ll INF = 1LL<<60; // Define a constant for infinity (not used in this code)
const ll MOD = 1000000007; // Define a constant for modulo operation (not used in this code)

//cout << fixed << setprecision(10); // Uncomment to set output precision (not used in this code)

int main() {
    ll a, b; // Declare two long long integers a and b
    cin >> a >> b; // Read values for a and b from standard input

    // Calculate the maximum of the sum, difference, and product of a and b
    cout << max(a + b, max(a - b, a * b)) << endl; // Output the maximum value

    return 0; // Return 0 to indicate successful execution
}
