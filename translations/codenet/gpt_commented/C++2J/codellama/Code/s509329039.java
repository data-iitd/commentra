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

public class Main {
    public static void main(String[] args) {
        // Read the number of constraints (n) and the number of conditions (m)
        int n, m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        // Initialize vectors to store the positions (s) and corresponding values (c)
        int[] s = new int[m];
        int[] c = new int[m];
        
        // Read the constraints into the vectors
        for (int i = 0; i < m; i++) {
            s[i] = sc.nextInt();
            c[i] = sc.nextInt();
            s[i]--; // Adjust for 0-based indexing
        }

        // Iterate through all possible numbers from 0 to 999
        for (int i = 0; i < 1000; i++) {
            String st = Integer.toString(i); // Convert the number to a string
            
            // Skip numbers that do not have the required length
            if (st.length() != n) {
                continue;
            }

            // Flag to check if the current number satisfies all conditions
            int f = 1;

            // Check each condition against the current number
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) == (c[j] + '0')) {
                    // Condition is satisfied
                } else {
                    // Condition is not satisfied, set flag to 0
                    f = 0;
                }
            }

            // If all conditions are satisfied, print the number and exit
            if (f) {
                System.out.println(i);
                return;
            }
        }

        // If no valid number is found, output -1
        System.out.println(-1);
    }
}

