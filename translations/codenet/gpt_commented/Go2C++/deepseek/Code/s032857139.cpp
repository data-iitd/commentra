#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <utility>
#include <map>
#include <set>
#include <typeinfo>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

// Constants for the program
const int MOD = 1000000007;
const int ALPHABET_NUM = 26;

int n, x;
vector<int> A;

// main function where the program execution starts
int main() {
    // Read input values for n and x
    cin >> n >> x;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sort the array A
    sort(A.begin(), A.end());

    // Initialize answer variable
    int ans = 0;
    // Count how many elements can be taken from A without exceeding x
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    // Adjust answer if all elements are taken and there is still remaining x
    if (ans == n && x > 0) {
        ans--;
    }
    // Print the final answer
    cout << ans << endl;

    return 0;
}
