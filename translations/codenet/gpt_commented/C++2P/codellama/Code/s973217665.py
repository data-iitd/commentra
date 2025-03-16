#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI

int main() {
    // Read the number of test cases
    int n;
    cin >> n;
    
    // Process each test case
    while (n--){
        int p, q;
        // Read the values of p and q
        cin >> p >> q;

        # Calculate the length l based on the Euclidean distance from the origin
        l = sqrt(p*p + q*q);
        
        # Initialize a flag to check if the current case is prime
        isprime = 1;

        # Check all combinations of i and j within the range [0, l)
        REP(i,l) REP(j,l) {
            # Calculate the sum of squares of i and j
            x = i*i + j*j;

            # Skip values of x that are not in the valid range
            if x <= 1 or x >= p*p + q*q:
                continue

            # Check the conditions for primality based on the given formula
            if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                isprime = 0 # Set isprime to false if conditions are met
        }

        # Output "P" if prime, otherwise output "C"
        print("P" if isprime else "C")
    }

    return 0 # End of the program
}

