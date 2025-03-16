
#include <bits/stdc++.h>

using namespace std;

// Define a structure for sorting pairs
struct pair {
	int64_t index;
	int64_t p1;
	int64_t p2;
};

// Implement sort.Interface for pairs
bool operator<(const pair &a, const pair &b) {
	return a.index < b.index;
}

// Define a structure for sorting int64 slices
struct Int64Slice {
	vector<int64_t> slice;
};

// Implement sort.Interface for Int64Slice
bool operator<(const Int64Slice &a, const Int64Slice &b) {
	return a.slice < b.slice;
}

// Utility functions for sorting int64 slices
void Int64s(vector<int64_t> &a) {
	sort(a.begin(), a.end());
}

bool Int64sSliceAreSorted(vector<int64_t> &a) {
	return is_sorted(a.begin(), a.end());
}

// Global variables for input/output handling and direction vectors
vector<int64_t> di = {-1, 0, 1, 0}; // Direction vectors for row movement
vector<int64_t> dj = {0, -1, 0, 1}; // Direction vectors for column movement

int main() {
	// Set up the scanner buffer and read three integers A, B, C
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int64_t A, B, C;
	cin >> A >> B >> C;
	
	// Check if C is within the range [A, B] and print the result
	if (C >= A && C <= B) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

/*==========================================
 *             Library Functions
 *==========================================*/

// NextPermutation generates the next lexicographical permutation of the given sort.Interface
bool NextPermutation(vector<int64_t> &x) {
	int64_t n = x.size() - 1;
	if (n < 1) {
		return false;
	}
	int64_t j = n - 1;
	// Find the rightmost ascent
	for (; !(x[j] < x[j+1]); j--) {
		if (j == 0) {
			return false;
		}
	}
	int64_t l = n;
	// Find the rightmost successor to the pivot
	for (; !(x[j] < x[l]); l--) {
	}
	swap(x[j], x[l]); // Swap the pivot with its successor
	// Reverse the suffix
	for (int64_t k = j+1, l = n; k < l; k++, l--) {
		swap(x[k], x[l]);
	}
	return true;
}

// doubleAry initializes a 2D slice with a given height, width, and initial value
vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
	vector<vector<int64_t>> res(h);
	for (int64_t i = 0; i < h; i++) {
		res[i] = vector<int64_t>(w, init);
	}
	return res;
}

// aryEq checks if two int64 slices are equal
bool aryEq(vector<int64_t> &a, vector<int64_t> &b) {
	return a == b;
}

// clone creates a copy of an int64 slice
vector<int64_t> clone(vector<int64_t> &n) {
	vector<int64_t> r(n.size());
	for (int64_t i = 0; i < n.size(); i++) {
		r[i] = n[i];
	}
	return r;
}

// write writes a string to the output buffer
void write(string s) {
	cout << s;
}

// print flushes the output buffer
void print() {
	cout.flush();
}

// readLine reads a line from the input
string readLine() {
	string s;
	getline(cin, s);
	return s;
}

// readInt reads an int64 from the input
int64_t readInt() {
	int64_t read;
	cin >> read;
	return read;
}

// readFloat reads a float64 from the input
float64_t readFloat() {
	float64_t read;
	cin >> read;
	return read;
}

// readRunes reads a string and returns its runes
vector<rune> readRunes() {
	string s;
	getline(cin, s);
	vector<rune> read;
	for (int64_t i = 0; i < s.size(); i++) {
		read.push_back(s[i]);
	}
	return read;
}

// readString reads a string from the input
string readString() {
	string read;
	cin >> read;
	return read;
}

// readStrings reads a string and returns its characters as a slice of strings
vector<string> readStrings() {
	string s;
	getline(cin, s);
	vector<string> read;
	for (int64_t i = 0; i < s.size(); i++) {
		read.push_back(string(1, s[i]));
	}
	return read;
}

// s2i converts a string to int64
int64_t s2i(string s) {
	int64_t intVal;
	stringstream ss(s);
	ss >> intVal;
	return intVal;
}

// i2s converts an int64 to string
string i2s(int64_t i) {
	string strVal;
	stringstream ss;
	ss << i;
	ss >> strVal;
	return strVal;
}

// s2f converts a string to float64
float64_t s2f(string s) {
	float64_t floatVal;
	stringstream ss(s);
	ss >> floatVal;
	return floatVal;
}

// abs returns the absolute value of an int64
int64_t abs(int64_t i) {
	return abs(i);
}

// max returns the maximum value from a variadic list of int64
int64_t max(vector<int64_t> a) {
	int64_t ans = 0;
	for (int64_t i = 0; i < a.size(); i++) {
		if (i == 0) {
			ans = a[i];
		}
		if (ans < a[i]) {
			ans = a[i];
		}
	}
	return ans;
}

// min returns the minimum value from a variadic list of int64
int64_t min(vector<int64_t> a) {
	int64_t ans = 0;
	for (int64_t i = 0; i < a.size(); i++) {
		if (i == 0) {
			ans = a[i];
		}
		if (ans > a[i]) {
			ans = a[i];
		}
	}
	return ans;
}

// sum calculates the sum of an int64 slice
int64_t sum(vector<int64_t> i) {
	int64_t sum = 0;
	for (int64_t j = 0; j < i.size(); j++) {
		sum += i[j];
	}
	return sum;
}

// split splits a string into fields
vector<string> split(string s) {
	return vector<string>(s.begin(), s.end());
}

// strAry2intAry converts a slice of strings to a slice of int64
vector<int64_t> strAry2intAry(vector<string> strs) {
	vector<int64_t> ret;
	for (int64_t i = 0; i < strs.size(); i++) {
		int64_t intVal = s2i(strs[i]);
		ret.push_back(intVal);
	}
	return ret;
}

// intAry2strAry converts a slice of int64 to a slice of strings
vector<string> intAry2strAry(vector<int64_t> nums) {
	vector<string> ret;
	for (int64_t i = 0; i < nums.size(); i++) {
		string strVal = i2s(nums[i]);
		ret.push_back(strVal);
	}
	return ret;
}

// ary2str joins a slice of strings into a single string
string ary2str(vector<string> strs) {
	stringstream ss;
	for (int64_t i = 0; i < strs.size(); i++) {
		ss << strs[i];
	}
	return ss.str();
}

// reverse reverses an int64 slice
vector<int64_t> reverse(vector<int64_t> res) {
	for (int64_t i = 0, j = res.size() - 1; i < j; i++, j--) {
		swap(res[i], res[j]);
	}
	return res;
}

// reverseStr reverses a string slice
vector<string> reverseStr(vector<string> res) {
	for (int64_t i = 0, j = res.size() - 1; i < j; i++, j--) {
		swap(res[i], res[j]);
	}
	return res;
}

// ini initializes the first element of a slice with a given value
void ini(vector<int> &res, int init) {
	if (res.size() == 0) {
		return;
	}
	res[0] = init;
	for (int64_t i = 0; i < res.size(); i++) {
		copy(res.begin() + i, res.begin() + i + 1, res.begin());
	}
}

// Uncomment the following function to see a regex example
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\\d+):(\\d+)");
//     cout << regex_replace(str, r, "$2:$1") << endl;
// }

// Uncomment the following struct and function to see a stable sort example
// struct Country {
//     int gold;
//     int silver;
//     int blonze;
// };

// // Example of stable sorting
// vector<Country> stableSortExample() {
//     vector<Country> country = {
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:3, blonze:2},
//         {gold:1, silver:3, blonze:3},
//     };
//     stable_sort(country.begin(), country.end(), [](const Country &a, const Country &b) { return a.blonze > b.blonze; });
//     stable_sort(country.begin(), country.end(), [](const Country &a, const Country &b) { return a.silver > b.silver; });
//     stable_sort(country.begin(), country.end(), [](const Country &a, const Country &b) { return a.gold > b.gold; });
//     return country;
// }

// 