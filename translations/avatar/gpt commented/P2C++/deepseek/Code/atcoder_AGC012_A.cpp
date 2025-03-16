#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>

using namespace std;

// Function to read a list of integers from input
vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
    }
    return A;
}

// Main function to execute the logic
void main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    int ans = 0;
    
    // Looping through the last 2*n elements of the sorted list in reverse order
    for (int i = A.size() - 2; i >= A.size() - 2 * n; i -= 2) {
        ans += A[i];
    }
    
    cout << ans << endl;
}

int main() {
    main();
    return 0;
}
