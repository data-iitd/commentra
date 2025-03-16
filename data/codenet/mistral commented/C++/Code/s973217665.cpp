
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

#define REP(i,n) for(int i=0; i<n; ++i) // For loop for iterating from 0 to n-1
#define FOR(i,a,b) for(int i=a; i<=b; ++i) // For loop for iterating from a to b
#define FORR(i,a,b) for (int i=a; i>=b; --i) // For loop for iterating from a to b in reverse order
#define pi M_PI // Constant value of pi

typedef long long ll; // Long long integer type
typedef vector<int> VI; // Vector of integers
typedef vector<ll> VL; // Vector of long long integers
typedef vector<VI> VVI; // Vector of vectors of integers
typedef pair<int,int> P; // Pair of integers
typedef pair<ll,ll> PL; // Pair of long long integers

int main() {
    int n; // Number of test cases
    cin >> n; // Read the number of test cases from standard input

    while (n--){ // Process each test case
        int p, q; // Read p and q from standard input
        cin >> p >> q;

        int l = sqrt(p*p + q*q); // Calculate the square root of p^2 + q^2

        bool isprime = 1; // Initialize isprime to true

        REP(i,l) REP(j,l) { // Iterate through all possible integers x from 0 to l^2
            int x = i*i + j*j; // Calculate x = i^2 + j^2

            if (x <= 1) continue; // If x is less than or equal to 1, skip to the next iteration
            if (x > p*p + q*q) continue; // If x is greater than p^2 + q^2, skip to the next iteration

            if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) { // Check if p*i + q*j and q*i - p*j are both divisible by x
                isprime = 0; // If so, set isprime to false
                break; // Exit the inner loop
            }
        }

        cout << (isprime ? "P" : "C") << endl; // Print "P" if isprime is still true, otherwise print "C"
    }

    return 0;
}

