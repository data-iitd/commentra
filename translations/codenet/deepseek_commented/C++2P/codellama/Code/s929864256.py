#include <iostream>
#include <algorithm> // For using the max function
#include <vector>    // Not used in this code
#include <map>       // Not used in this code
#include <set>       // Not used in this code
#include <string>    // Not used in this code
#include <queue>     // Not used in this code
#include <list>      // Not used in this code
#include <cmath>     // Not used in this code
#include <stack>     // Not used in this code
#include <iomanip>   // Not used in this code

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60; // Define a constant for infinity
const ll MOD = 1000000007; // Define a constant for modulo operation

//cout << fixed << setprecision(10); // Not used in this code

int main() {
    ll a,b;
    cin >> a >> b; // Read two long long integers from standard input

    # Compute the maximum value among a+b, a-b, and a*b
    print(max(a+b,max(a-b,a*b))) # Print the maximum value

    return 0; # Return 0 indicating successful execution
}

