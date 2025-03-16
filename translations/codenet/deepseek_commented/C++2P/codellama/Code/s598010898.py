#include <iostream>
#include <algorithm> // For std::sort
#include <sstream>   // For std::stringstream
#include <cmath>     // For mathematical functions
#include <vector>    // For std::vector
#include <iomanip>   // For std::setprecision
#include <map>       // For std::map
#include <set>       // For std::set
#include <queue>     // For std::queue
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void) {
    int n, a[100], b[100], sum = 0;
    cin >> n; // Read the number of elements

    # Read n integers into array a
    rep(i, n) cin >> a[i];

    # Read n integers into array b
    rep(i, n) {
        cin >> b[i];
        if (a[i] - b[i] > 0) { # Check if a[i] is greater than b[i]
            sum += a[i] - b[i]; # Add the difference to sum
        }
    }

    # Output the sum
    cout << sum << endl;
}

