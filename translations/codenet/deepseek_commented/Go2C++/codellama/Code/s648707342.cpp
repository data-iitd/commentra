
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Defines a struct to represent an arm with left and right endpoints.
struct arm {
	int l, r;
};

// Reads a single integer from standard input.
int scanInt() {
	int iv;
	cin >> iv;
	return iv;
}

// Initializes the scanner to split input by words.
void init() {
	cin.ignore();
}

int main() {
	// Reads the number of arms.
	int n = scanInt();
	
	// Creates a vector to store the arms.
	vector<arm> as(n);
	
	// Reads each arm's range and stores the left and right endpoints.
	for (int i = 0; i < n; i++) {
		int x, l;
		cin >> x >> l;
		as[i].l = x - l;
		as[i].r = x + l;
	}
	
	// Sorts the arms based on their right endpoints.
	sort(as.begin(), as.end(), [](const arm& a, const arm& b) {
		return a.r < b.r;
	});
	
	// Initializes the answer and the right endpoint reference.
	int ans = 1;
	int r = as[0].r;
	
	// Iterates through the sorted arms to count non-overlapping arms.
	for (int i = 1; i < n; i++) {
		if (as[i].l >= r) {
			ans++;
			r = as[i].r;
		}
	}
	
	// Prints the count of non-overlapping arms.
	cout << ans << endl;
	
	return 0;
}

