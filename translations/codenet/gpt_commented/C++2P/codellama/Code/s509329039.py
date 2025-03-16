#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     // Note: The size of the vector must be known at compile time and cannot be changed
#include <cassert>
#include <iomanip>        // For setprecision
#include <ctime>
#include <complex>
using namespace std;

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

#define pi 3.14159265358979323846264
#define mod 1000000007

int main() {
    # Read the number of constraints (n) and the number of conditions (m)
    n, m = map(int, input().split())

    # Initialize vectors to store the positions (s) and corresponding values (c)
    s = [0] * m
    c = [0] * m

    # Read the constraints into the vectors
    for i in range(m):
        s[i], c[i] = map(int, input().split())
        s[i] -= 1 # Adjust for 0-based indexing

    # Iterate through all possible numbers from 0 to 999
    for i in range(1000):
        st = str(i) # Convert the number to a string

        # Skip numbers that do not have the required length
        if len(st) != n:
            continue

        # Flag to check if the current number satisfies all conditions
        f = 1

        # Check each condition against the current number
        for j in range(m):
            if st[s[j]] == str(c[j]):
                # Condition is satisfied
            else:
                # Condition is not satisfied, set flag to 0
                f = 0

        # If all conditions are satisfied, print the number and exit
        if f:
            print(i)
            return 0

    # If no valid number is found, output -1
    print(-1)

