
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Initialize a new scanner object
class Scanner {
public:
	Scanner() {
		r = new istream(cin.rdbuf());
	}

	// Read a single token from the standard input
	string Next() {
		pre();
		start = p;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				break;
			}
		}
		string result = buf.substr(start, p - start);
		p++;
		return result;
	}

	// Read a line from the standard input
	string NextLine() {
		pre();
		start = p;
		p = buf.size();
		return buf.substr(start);
	}

	// Read an integer from the standard input
	int NextInt() {
		return atoi(Next().c_str());
	}

	// Read an array of integers from the standard input
	vector<int> NextIntArray() {
		pre();
		start = p;
		vector<int> result;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				string s = buf.substr(start, p - start);
				result.push_back(atoi(s.c_str()));
				start = p + 1;
			}
		}
		string s = buf.substr(start, p - start);
		result.push_back(atoi(s.c_str()));

		return result;
	}

	// Read a map from the standard input
	map<int, bool> NextMap() {
		pre();
		start = p;
		map<int, bool> mp;
		for (; p < buf.size(); p++) {
			if (buf[p] == ' ') {
				string s = buf.substr(start, p - start);
				mp[atoi(s.c_str())] = true;
				start = p + 1;
			}
		}
		string s = buf.substr(start, p - start);
		mp[atoi(s.c_str())] = true;

		return mp;
	}

private:
	// Prepare the scanner for the next read operation
	void pre() {
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}

	// Read a line from the standard input
	void readLine() {
		buf = "";
		for (;;) {
			string line;
			getline(*r, line);
			buf += line;
			if (!r->good()) {
				break;
			}
		}
	}

	istream* r;
	string buf;
	int p, start;
};

// Initialize a new scanner object
int main() {
	Scanner sc;

	// Read the number of elements in the array from the standard input
	int n = sc.NextInt();

	// Allocate memory for the array of size n
	vector<double> arr(n);

	// Read n integers from the standard input and store them in the array
	for (int i = 0; i < n; i++) {
		arr[i] = sc.NextInt();
	}

	// Sort the array in ascending order
	sort(arr.begin(), arr.end());

	// Initialize a variable prev to store the previous element in the sorted array
	double prev = arr[0];

	// Iterate through the sorted array from the second element to the last
	for (int i = 1; i < arr.size(); i++) {
		// Calculate the average of the previous and current elements
		prev = (prev + arr[i]) / 2;
	}

	// Print the result to the standard output
	cout << prev << endl;

	return 0;
}

