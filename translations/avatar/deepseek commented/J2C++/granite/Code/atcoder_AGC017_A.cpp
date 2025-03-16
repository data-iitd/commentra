

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#include <iomanip>
#include <complex>
#include <list>
#include <tuple>
#include <cstdint>
#include <random>
#include <functional>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

// Function to calculate combination (n choose m) using BigInteger for large numbers
BigInteger C(int n, int m) { 
    BigInteger res = new BigInteger("1"); // Initialize result to 1
    // Calculate product from m-n+1 to m
    for (int i = m - n + 1; i <= m; i++) 
        res = res.multiply(BigInteger.valueOf(i)); 
    // Divide by product from 1 to n
    for (int i = 1; i <= n; i++) 
        res = res.divide(BigInteger.valueOf(i)); 
    return res; 
} 

int main() { 
    int n, p; 
    int k0 = 0; // Count of even numbers
    int k1 = 0; // Count of odd numbers

    // Read number of items (n) and the value of p
    cin >> n >> p; 

    // Count even and odd numbers in the input
    for (int i = 0; i < n; i++) { 
        int x; cin >> x; 
        if (x % 2 == 1) 
            k1++; 
        else 
            k0++; 
    } 

    // Initialize result for number of ways to arrange items
    BigInteger ans = new BigInteger("1"); 

    // Calculate number of ways based on the value of p
    for (int i = 0; i < k0; i++) 
        ans = ans.multiply(BigInteger.valueOf(2)); // Multiply by 2 for each even number

    if (p == 0) { 
        BigInteger add = new BigInteger("0"); 
        // Sum combinations of odd numbers, taking 0, 2, 4,... odd numbers
        for (int i = 0; i <= k1; i += 2) 
            add = add.add(C(i, k1)); 
        ans = ans.multiply(add); // Multiply result by the sum
        cout << ans << endl; // Print final result
    } else { 
        BigInteger add = new BigInteger("0"); 
        // Sum combinations of odd numbers, taking 1, 3, 5,... odd numbers
        for (int i = 1; i <= k1; i += 2) 
            add = add.add(C(i, k1)); 
        ans = ans.multiply(add); // Multiply result by the sum
        cout << ans << endl; // Print final result
    } 

    return 0; 
}
