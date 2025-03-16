

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
    int a, b; // Declare two integer variables 'a' and 'b'
    int ans; // Declare an integer variable 'ans' to store the answer

    cin >> a >> b; // Read two integers from the standard input and store them in variables 'a' and 'b'

    ans = 0; // Initialize the answer variable 'ans' to zero

    // Check if 'a' is greater than or equal to 13
    if (a >= 13) {
        ans = b; // If 'a' is greater than or equal to 13, then the answer is 'b'
    }

    // Else if 'a' is greater than or equal to 6
    else if (a >= 6) {
        ans = b/2; // If 'a' is greater than or equal to 6, then the answer is half of 'b'
    }

    cout << ans << endl; // Print the answer to the standard output

    return 0; // Indicate successful termination of the program
}

