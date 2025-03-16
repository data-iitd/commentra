#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cassert>
#include <limits>
#include <typeinfo>
#include <ciso646>
using namespace std;

int main() {
    // Read an integer input from the user
    int n;
    cin >> n;
    
    // Initialize a variable to hold the final result
    long long ans = 0;
    
    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i < n + 1; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long long) i * ((long long) n / (long long) i) * (((long long) n / (long long) i) + 1) / 2;
    }
    
    // Output the final result
    cout << ans << endl;
    
    return 0;
}

