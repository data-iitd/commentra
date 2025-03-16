
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <utility>
#include <iterator>
#include <list>
#include <deque>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <cfloat>
#include <ciso646>
#include <cstdbool>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
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
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <utility>
#include <valarray>
#include <variant>
#include <memory>
#include <shared_ptr>
#include <unique_ptr>
#include <weak_ptr>
#include <scoped_allocator>
#include <stack>
#include <queue>
#include <priority_queue>
#include <span>
#include <stop_token>
#include <version>

// Define the readInt function to read a single integer from the standard input
int readInt() {
	int n;
	std::cin >> n;
	return n;
}

// Define the readFloat64 function to read a single float64 from the standard input
double readFloat64() {
	double f;
	std::cin >> f;
	return f;
}

// Define the readString function to read a single string from the standard input
std::string readString() {
	std::string s;
	std::cin >> s;
	return s;
}

// Main function to execute the program
int main() {
	// Read two integers n and m from the input
	int n = readInt();
	int m = readInt();

	// Initialize a vector to hold m integers
	std::vector<int> a(m);
	int sum = 0;

	// Read m integers into the vector a and calculate their sum
	for (int i = 0; i < m; i++) {
		a[i] = readInt();
		sum += a[i];
	}

	// Check if the sum of integers exceeds n
	if (sum > n) {
		// Print -1 if the sum exceeds n and exit
		std::cout << "-1" << std::endl;
		return 0;
	}

	// Print the difference between n and the sum if it's within bounds
	std::cout << n - sum << std::endl;

	return 0;
}

// End of code
