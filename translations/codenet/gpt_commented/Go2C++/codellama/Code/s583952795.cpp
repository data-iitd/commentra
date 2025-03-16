
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

// Pair struct to hold two values of any type
template <typename T1, typename T2>
struct Pair {
	T1 p1;
	T2 p2;
};

// Constants for buffer sizes
const int initialBufSize = 1e4; // Initial buffer size for scanner
const int maxBufSize = 1e8; // Maximum buffer size for scanner

// Global variables for input and output
string readLine();

// Function to convert a number from base 10 to base N
template <typename T>
string TenToN(T number, T n) {
	string s; // String to hold the result
	T tmp = number; // Temporary variable to hold the current number
	while (true) {
		// Prepend the remainder of the division to the result string
		s = to_string(tmp % n) + s;
		if (tmp < n) { // If the temporary number is less than the base, exit the loop
			break;
		}
		tmp /= n; // Divide the temporary number by the base
	}
	return s; // Return the converted string
}

// Function to write a string to the output
void write(string s) {
	cout << s;
}

// Function to flush the writer buffer to output
void print() {
	cout.flush();
}

// Function to read a line of input
string readLine() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read an integer from input
int readInt() {
	string s = readLine();
	return stoi(s);
}

// Function to read a float from input
float readFloat() {
	string s = readLine();
	return stof(s);
}

// Function to read runes from input
vector<char> readRunes() {
	string s = readLine();
	vector<char> v;
	for (char c : s) {
		v.push_back(c);
	}
	return v;
}

// Function to read a string from input
string readString() {
	return readLine();
}

// Function to read a slice of strings from input
vector<string> readStrings() {
	string s = readLine();
	vector<string> v;
	for (char c : s) {
		v.push_back(string(1, c));
	}
	return v;
}

// Function to convert a string to an integer
int s2i(string s) {
	int intVal;
	try {
		intVal = stoi(s);
	} catch (invalid_argument e) {
		panic(e);
	}
	return intVal;
}

// Function to convert an integer to a string
string i2s(int i) {
	string strVal = to_string(i);
	return strVal;
}

// Function to convert a string to a float
float s2f(string s) {
	float floatVal;
	try {
		floatVal = stof(s);
	} catch (invalid_argument e) {
		panic(e);
	}
	return floatVal;
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
	return vector<string>(s.begin(), s.end());
}

// Function to convert a slice of strings to a slice of integers
vector<int> strAry2intAry(vector<string> strs) {
	vector<int> ret;
	for (string str : strs) {
		int intVal;
		try {
			intVal = stoi(str);
		} catch (invalid_argument e) {
			panic(e);
		}
		ret.push_back(intVal);
	}
	return ret;
}

// Function to convert a slice of integers to a slice of strings
vector<string> intAry2strAry(vector<int> nums) {
	vector<string> ret;
	for (int num : nums) {
		string strVal = to_string(num);
		ret.push_back(strVal);
	}
	return ret;
}

// Function to join a slice of strings into a single string
string ary2str(vector<string> strs) {
	string ret = "";
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
template <typename T>
void initalize(vector<T> &res, T init) {
	if (res.size() == 0) {
		return;
	}
	res[0] = init;
	for (int i = 0; i < res.size(); i++) {
		copy(res.begin() + i, res.begin() + i + 1, res.begin());
	}
}

// Example function for regular expressions (commented out)
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\\d+):(\\d+)");
//     cout << regex_replace(str, r, "$1:$2") << endl;
// }

// Struct to hold medal counts for a country (commented out)
// struct Country {
//     int gold;
//     int silver;
//     int blonze;
// };

// // Example function for stable sorting (commented out)
// vector<Country> stableSortExample() {
//     vector<Country> country = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     stable_sort(country.begin(), country.end(), [](Country a, Country b) { return a.blonze > b.blonze; });
//     stable_sort(country.begin(), country.end(), [](Country a, Country b) { return a.silver > b.silver; });
//     stable_sort(country.begin(), country.end(), [](Country a, Country b) { return a.gold > b.gold; });
//     return country;
// }

int main() {
	// Allocate buffer for scanner and set its maximum size
	string buf(initialBufSize, ' ');
	cin.rdbuf()->pubsetbuf(buf.data(), maxBufSize);

	// Read two integers N and K from input
	int N, K;
	N = readInt();
	K = readInt();
	// Convert the number N from base 10 to base K
	string s = TenToN(N, K);
	// Print the length of the resulting string
	cout << s.length() << endl;

	// Your code here!

	// Print the end of code
	cout << "