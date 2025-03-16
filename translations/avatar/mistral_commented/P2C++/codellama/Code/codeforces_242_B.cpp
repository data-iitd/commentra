#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// Define lambda functions for reading input
auto I = [] () {
    int n;
    cin >> n;
    return vector<int> ( n );
};
auto IS = [] () {
    string s;
    cin >> s;
    return s;
};
auto IN = [] () {
    int n;
    cin >> n;
    return n;
};
auto IF = [] () {
    double n;
    cin >> n;
    return n;
};

// Read the number of test cases
int n = IN ( );

// Initialize id variable to 0
int id = 0;

// Read left and right boundary values for the first test case
int l, r;
cin >> l >> r;

// Iterate through the remaining test cases
for ( int i = 1 ; i < n ; i++ ) {
    // Read left and right boundary values for the current test case
    int li, ri;
    cin >> li >> ri;

    // Check if the current test case overlaps with the previously defined boundary values
    if ( li <= l && r <= ri ) {
        // Update id variable to the index of the current test case
        id = i;
    }

    // If the current test case does not overlap, keep id as n
    else if ( li < l || r < ri ) {
        id = n;
    }

    // Update boundary values based on the current test case
    l = min ( l , li );
    r = max ( r , ri );
}

// Print the index of the test case that satisfies the condition, or -1 if no such test case exists
cout << ( id == n ? -1 : id + 1 ) << endl;


