#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll; // Define long long integer as ll for better readability

ll ans, mx, sum, mn = 1e8, cnt = 1; // Initialize variables

int main() {
	ll h; // Initialize variable h to store input integer

	// Read input integer h from standard input
	cin >> h;

	// Loop until h becomes 1
	while (h != 1) {
		// If h is odd, decrement it by 1
		if (h % 2 != 0) h--;

		// Divide h by 2 and multiply cnt by 2
		h /= 2;
		cnt *= 2;

		// Add the new value of cnt to the answer
		ans += cnt;
	}

	// Output the final answer plus 1
	cout << ans + 1 << endl;
}
