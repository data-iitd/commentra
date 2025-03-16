
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
#include <time.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Reading the values of N, d, and x from standard input
int main() {
    int N, d, x;
    cin >> N >> d >> x;

    // Defining the main function to calculate a result based on N, d, and x
    int ret = 0;  // Initializing the result variable to accumulate the result
    while (N) {  // Running the loop while N is greater than 0
        // Incrementing ret by the sum of d and (N - 0.5) * x
        ret += d + (N - 0.5) * x;
        
        // Updating the value of d using a complex formula
        d = d + (d / N) + (5 * x) / (2 * N);
        
        // Updating the value of x using another formula
        x += 2 * x / N;
        
        // Decrementing N by 1
        N--;
    }

    // Printing the result of the main function
    cout << ret << endl;

    return 0;
}

