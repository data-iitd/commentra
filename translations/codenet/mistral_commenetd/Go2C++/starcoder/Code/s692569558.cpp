
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <cfloat>
#include <ciso646>
#include <typeinfo>
#include <stdexcept>
#include <new>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <ratio>
#include <array>
#include <valarray>
#include <atomic>
#include <cfenv>
#include <random>
#include <regex>
#include <complex>
#include <initializer_list>
#include <tuple>
#include <utility>
#include <type_traits>
#include <bitset>
#include <csetjmp>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iterator>
#include <memory>
#include <limits>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <cfloat>
#include <ciso646>
#include <typeinfo>
#include <stdexcept>
#include <new>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <ratio>
#include <array>
#include <valarray>
#include <atomic>
#include <cfenv>
#include <random>
#include <regex>
#include <complex>
#include <initializer_list>
#include <tuple>
#include <utility>
#include <type_traits>
#include <bitset>
#include <csetjmp>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iterator>
#include <memory>
#include <limits>
#include <numeric>
#include <ratio>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	// Initialize a new scanner for reading from standard input
	string ds;
	cin >> ds;

	// Split the string ds into an array of strings dd using the strings.Split function
	vector<string> dd = split(ds, " ");

	// Create a new vector of integers dn of length dd.size() and initialize each element to 0 using make_pair function
	vector<int> dn = make_pair(dd.size(), 0);

	// Iterate through each element i in the vector dd and convert its string value to integer using stoi function and store it in the corresponding index of vector dn
	for (int i = 0; i < dd.size(); i++) {
		dn[i] = stoi(dd[i]);
	}

	// Initialize sum variable to 0
	int sum = 0;

	// Iterate through each index i in the vector dn
	for (int i = 0; i < dn.size(); i++) {
		// Iterate through each index j greater than i in the vector dn
		for (int j = i + 1; j < dn.size(); j++) {
			// Add the product of dn[i] and dn[j] to the sum variable
			sum += dn[i] * dn[j];
		}
	}

	// Print the value of sum variable to the standard output using cout function
	cout << sum << endl;

	// End of code
}

