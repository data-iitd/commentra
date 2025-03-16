#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read two integers N and K from standard input
	int N, K;
	cin >> N >> K;

	// Convert N to base K and print the length of the resulting string
	string s = tenToN(N, K);
	cout << s.length() << endl;
}

// tenToN converts a decimal number to a base N string
string tenToN(int number, int n) {
	string s;
	int tmp = number;
	while (true) {
		s = to_string(tmp % n) + s;
		if (tmp < n) {
			break;
		}
		tmp /= n;
	}
	return s;
}

/*==========================================
 *             Library
 *==========================================*/

// to_string converts an integer to a string
string to_string(int num) {
	string s;
	if (num == 0) {
		s = "0";
	}
	while (num > 0) {
		s = char(num%10 + '0') + s;
		num /= 10;
	}
	return s;
}

// strAry2intAry converts a slice of strings to a slice of integers
vector<int> strAry2intAry(vector<string> strs) {
	vector<int> ret;
	for (string str : strs) {
		int intVal;
		stringstream ss(str);
		ss >> intVal;
		ret.push_back(intVal);
	}
	return ret;
}

// intAry2strAry converts a slice of integers to a slice of strings
vector<string> intAry2strAry(vector<int> nums) {
	vector<string> ret;
	for (int num : nums) {
		string strVal = to_string(num);
		ret.push_back(strVal);
	}
	return ret;
}

// ary2str joins a slice of strings into a single string with spaces
string ary2str(vector<string> strs) {
	string ret;
	for (string str : strs) {
		ret += str + " ";
	}
	return ret;
}

// reverse reverses a slice of integers
vector<int> reverse(vector<int> res) {
	for (int i = 0; i < res.size()/2; i++) {
		int tmp = res[i];
		res[i] = res[res.size()-1-i];
		res[res.size()-1-i] = tmp;
	}
	return res;
}

// initalize initializes a slice with a given value
void initalize(vector<int> res, int init) {
	if (res.size() == 0) {
		return;
	}
	res[0] = init;
	for (int i = 0; i < res.size(); i++) {
		copy(res.begin()+i, res.begin()+i+1, res.begin());
	}
}

// func regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\d+):(\d+)");
//     smatch m;
//     if (regex_search(str, m, r)) {
//         cout << m[0] << endl;
//         cout << m[1] << endl;
//         cout << m[2] << endl;
//     }
// }

// struct Country {
//     int gold;
//     int silver;
//     int blonze;
// };

// // 複数ソートのサンプル
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

