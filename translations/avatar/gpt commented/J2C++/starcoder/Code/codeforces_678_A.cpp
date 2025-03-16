#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cfloat>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cctype>
#include <bitset>
using namespace std;

int main() {
    // Read two integers from the user: n and k
    int n, k;
    cin >> n >> k;
    
    // Increment n by 1
    n++;
    
    // Initialize a variable z to store the adjustment needed to make n divisible by k
    int z = 0;
    
    // Check if n is not divisible by k
    if (n % k!= 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    cout << n + z << endl;
    
    return 0;
}

