#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

// Macro definitions for convenience
#define REP(i,n) for(int i=0;i<n;i++) // Repeat macro for loops
#define all(x) (x).begin(),(x).end() // Macro to get all elements of a container
#define mp make_pair // Macro to create a pair
#define pb push_back // Macro to add an element to the end of a vector
#define eb emplace_back // Macro to add an element to the end of a vector with construction

typedef long long ll; // Define long long type as ll
using namespace std;

int main(void) {
    // Synchronize input/output for faster performance
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // Read the number of elements
    int n;
    cin >> n;
    
    // Initialize a vector to store the elements and read them from input
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    // Sort the vector to facilitate duplicate checking
    sort(all(a));
    
    // Check for duplicates in the sorted vector
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            // If a duplicate is found, print "NO" and exit
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    // If no duplicates are found, print "YES"
    cout << "YES" << '\n';
    
    return 0; // End of the program
}
