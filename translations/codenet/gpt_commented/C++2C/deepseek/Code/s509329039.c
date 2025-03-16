#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Macro definitions for loop constructs and data types
#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

// Constants for mathematical calculations
const double pi = 3.14159265358979323846264;
const int mod = 1000000007;

int main() {
    // Read the number of constraints (n) and the number of conditions (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize arrays to store the positions (s) and corresponding values (c)
    int s[m], c[m];
    
    // Read the constraints into the arrays
    FOR(i, 0, m) {
        scanf("%d %d", &s[i], &c[i]);
        s[i]--; // Adjust for 0-based indexing
    }

    // Iterate through all possible numbers from 0 to 999
    FOR(i, 0, 1000) {
        char st[10]; // Buffer to hold the string representation of the number
        sprintf(st, "%0*d", n, i); // Convert the number to a string with leading zeros
        
        // Skip numbers that do not have the required length
        if (strlen(st) != n) {
            continue;
        }

        // Flag to check if the current number satisfies all conditions
        int f = 1;

        // Check each condition against the current number
        FOR(j, 0, m) {
            if (st[s[j]] == c[j] + '0') {
                // Condition is satisfied
            } else {
                // Condition is not satisfied, set flag to 0
                f = 0;
            }
        }

        // If all conditions are satisfied, print the number and exit
        if (f) {
            printf("%d\n", i);
            return 0;
        }
    }

    // If no valid number is found, output -1
    printf("-1\n");
}
