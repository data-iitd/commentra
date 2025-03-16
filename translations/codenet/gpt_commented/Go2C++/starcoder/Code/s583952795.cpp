#include <bits/stdc++.h>

using namespace std;

// Function to write a string to the output
void write(string s) {
	cout << s;
}

// Function to flush the writer buffer to output
void print() {
	cout << endl;
}

// Function to read a line of input
string readLine() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read an integer from input
int readInt() {
	int n;
	cin >> n;
	return n;
}

// Function to read a float from input
float readFloat() {
	float n;
	cin >> n;
	return n;
}

// Function to read runes from input
vector<char> readRunes() {
	vector<char> s;
	char c;
	while (cin >> c) {
		s.push_back(c);
	}
	return s;
}

// Function to read a string from input
string readString() {
	string s;
	cin >> s;
	return s;
}

// Function to read a slice of strings from input
vector<string> readStrings() {
	vector<string> s;
	string t;
	while (cin >> t) {
		s.push_back(t);
	}
	return s;
}

// Function to convert a string to an integer
int s2i(string s) {
	int n;
	istringstream(s) >> n;
	return n;
}

// Function to convert an integer to a string
string i2s(int n) {
	return to_string(n);
}

// Function to convert a string to a float
float s2f(string s) {
	float n;
	istringstream(s) >> n;
	return n;
}

// Function to calculate the sum of a slice of integers
int sum(vector<int> i) {
	int sum = 0;
	for (int val : i) {
		sum += val;
	}
	return sum;
}

// Function to split a string into a slice of strings
vector<string> split(string s) {
	return split(s, " ");
}

// Function to split a string into a slice of strings
vector<string> split(string s, string delim) {
	vector<string> ret;
	size_t pos = 0;
	while (pos < s.size()) {
		size_t next = s.find(delim, pos);
		if (next == string::npos) {
			ret.push_back(s.substr(pos));
			break;
		}
		ret.push_back(s.substr(pos, next - pos));
		pos = next + delim.size();
	}
	return ret;
}

// Function to convert a slice of strings to a slice of integers
vector<int> strAry2intAry(vector<string> strs) {
	vector<int> ret;
	for (string str : strs) {
		int n;
		istringstream(str) >> n;
		ret.push_back(n);
	}
	return ret;
}

// Function to convert a slice of integers to a slice of strings
vector<string> intAry2strAry(vector<int> nums) {
	vector<string> ret;
	for (int num : nums) {
		ret.push_back(to_string(num));
	}
	return ret;
}

// Function to join a slice of strings into a single string
string ary2str(vector<string> strs) {
	string ret;
	for (string str : strs) {
		ret += str + " ";
	}
	return ret;
}

// Function to reverse a slice of integers
vector<int> reverse(vector<int> res) {
	for (int i = 0, j = res.size() - 1; i < j; i++, j--) {
		swap(res[i], res[j]);
	}
	return res;
}

// Function to initialize a slice with a given value
void initalize(vector<int> res, int init) {
	if (res.size() == 0) {
		return;
	}
	res[0] = init;
	for (int i = 0; i < res.size(); i++) {
		copy(res.begin() + i, res.begin() + i, res.begin());
	}
}

// Example function for regular expressions
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\d+):(\d+)");
//     smatch m;
//     if (regex_search(str, m, r)) {
//         cout << m[1] << " " << m[2] << endl;
//     }
// }

// Struct to hold medal counts for a country
// struct Country {
//     int gold;
//     int silver;
//     int blonze;
// };

// // Example function for stable sorting
// vector<Country> stableSortExample() {
//     vector<Country> country = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     sort(country.begin(), country.end(), [](Country a, Country b) { return a.blonze > b.blonze; });
//     sort(country.begin(), country.end(), [](Country a, Country b) { return a.silver > b.silver; });
//     sort(country.begin(), country.end(), [](Country a, Country b) { return a.gold > b.gold; });
//     return country;
// }

