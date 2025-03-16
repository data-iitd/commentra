#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

// Constants definition
const ll INF = 1LL<<60; // Infinite value for long long int
const ll MOD = 1000000007; // Modulus value for modular arithmetic

// Input output functions
int main() {
    // Initialize variables
    ll a, b;

    // Read input values from standard input
    cin >> a >> b;

    // Calculate the maximum value among a+b, a-b, and a*b
    ll result = max(a+b, max(a-b, a*b));

    // Output the result to standard output
    cout << result << endl;

    // End of the program
    return 0;
}
