
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

#define REP(i,n) for(int i=0;i<n;i++) // Define a macro REP for repetition
#define all(x) (x).begin(),(x).end() // Define a macro all for getting the begin and end iterators of a container
#define mp make_pair // Define a macro mp for making a pair
#define pb push_back // Define a macro pb for pushing an element to the back of a container
#define eb emplace_back // Define a macro eb for emplacing an element to the back of a container

typedef long long ll; // Define a new type alias for long long
using namespace std; // Use the std namespace

int main(void){ // The main function
    cin.tie(0); // Tie the cin object to cout to improve performance
    ios::sync_with_stdio(false); // Disable synchronization between cin, cout, and the standard input/output buffers

    // Read the number of elements in the vector
    int n;
    cin >> n;

    // Initialize a vector of size n with default-constructed elements
    vector<int> a(n);

    // Read the elements of the vector
    REP(i,n) cin >> a[i];

    // Sort the vector in ascending order
    sort(all(a));

    // Check if there are any consecutive elements in the sorted vector
    REP(i,n-1){
        // If there are consecutive elements, print "NO" and exit the program
        if(a[i] == a[i+1]){
            cout << "NO" << '\n';
            return 0;
        }
    }

    // If no consecutive elements were found, print "YES"
    cout << "YES" << '\n';

    return 0; // Indicate successful termination of the program
}