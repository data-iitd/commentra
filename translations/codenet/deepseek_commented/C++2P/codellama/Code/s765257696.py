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
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false); // Comment 2: Optimizes input/output streams
    cin.tie(0); // Comment 2: Syncs the cin and cout streams
    cout.tie(0); // Comment 2: Syncs the cout stream

    int n;
    cin >> n; // Comment 3: Reads the size of the array p from standard input

    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i]; // Comment 4: Populates the array p with n integers from standard input

    int ans = 0; // Comment 5: Initializes the variable ans to 0

    for (int i = 0; i < n - 2; i++) { // Comment 6: Loops through the array p
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++; // Comment 7: Checks for a peak and increments ans
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++; // Comment 8: Checks for a valley and increments ans
    }

    cout << ans << "\n"; // Comment 9: Prints the final value of ans to standard output
    return 0; // Comment 10: Ends the program by returning 0
}

