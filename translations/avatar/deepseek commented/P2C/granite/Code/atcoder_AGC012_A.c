
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <bitset>
#include <cassert>
#include <exception>
#include <numeric>
#include <functional>
#include <fstream>
#include <iomanip>
#include <locale>
#include <random>
#include <regex>
#include <system_error>
#include <tuple>
#include <utility>
#include <valarray>
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <forward_list>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <thread>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>

using namespace std;

// Function to read integers from input
vector<int> readInts() {
    int n;
    cin >> n;  // Read integer n
    vector<int> A(n);  // Initialize vector A with length n
    for (int i = 0; i < n; i++) {
        cin >> A[i];  // Read integer A[i]
    }
    return A;  // Return the vector A
}

// Main function
int main() {
    int n = readInts()[0];  // Read integer n
    vector<int> A = readInts();  // Read list A
    sort(A.begin(), A.end());  // Sort the list A
    int ans = 0;  // Initialize answer variable
    
    // Calculate the sum of every second element from the end
    for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
        ans += A[i];  // Add the current element to the answer
    }
    
    cout << ans << endl;  // Print the calculated sum
    return 0;
}

Translate the above C code to Java and end with comment "