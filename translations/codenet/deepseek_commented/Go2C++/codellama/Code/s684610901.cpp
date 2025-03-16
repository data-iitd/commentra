
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

// Package main defines the entry point for the program.

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
// pair struct holds two values and an index for sorting.
struct pair {
	int64_t index;
	int64_t p1;
	int64_t p2;
};

// pairs is a slice of pair structs for sorting.
struct pairs {
	vector<pair> slice;
	int64_t Len() {
		return slice.size();
	}
	bool Less(int i, int j) {
		return slice[i].index < slice[j].index;
	}
	void Swap(int i, int j) {
		pair temp = slice[i];
		slice[i] = slice[j];
		slice[j] = temp;
	}
};

// Int64Slice is a type alias for sorting slices of int64.
struct Int64Slice {
	vector<int64_t> slice;
	int64_t Len() {
		return slice.size();
	}
	bool Less(int i, int j) {
		return slice[i] < slice[j];
	}
	void Swap(int i, int j) {
		int64_t temp = slice[i];
		slice[i] = slice[j];
		slice[j] = temp;
	}
};

// Int64s sorts a slice of int64.
void Int64s(Int64Slice slice) {
	sort(slice.slice.begin(), slice.slice.end());
}

// Int64sSliceAreSorted checks if a slice of int64 is sorted.
bool Int64sSliceAreSorted(Int64Slice slice) {
	return is_sorted(slice.slice.begin(), slice.slice.end());
}

/*==========================================
 *             Constants and Variables
 *==========================================*/
// scanner and writer are initialized for reading from standard input and writing to standard output.
istream& scanner(cin);
ostream& writer(cout);

// di and dj define the four directions for a robot.
vector<int64_t> di = { -1, 0, 1, 0 };
vector<int64_t> dj = { 0, -1, 0, 1 };

/*==========================================
 *             Main Function
 *==========================================*/
// main function reads three integers and checks if the third integer lies between the first and second.
int main() {
	int64_t A, B, C;
	cin >> A >> B >> C;
	if (C >= A && C <= B) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

// END-OF-CODE
