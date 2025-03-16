
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ReadLongLines reads multiple lines of input from stdin.
// It uses a buffer to accumulate the input and reads line by line until it reaches the end of the file.
vector<string> ReadLongLines(int times) {
	vector<string> result(times);
	string buffer;
	for (int i = 0; i < times; i++) {
		getline(cin, buffer);
		result[i] = buffer;
	}
	return result;
}

// PrintList prints a list of integers separated by spaces.
void PrintList(vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		if (i == 0) {
			cout << list[i];
		} else {
			cout << " " << list[i];
		}
	}
	cout << endl;
}

int main() {
	// Create a map to store unique elements.
	map<int, int> m;
	vector<string> lines = ReadLongLines(4);

	// Split the second line into individual elements and add them to the map.
	vector<string> a = split(lines[1], " ");
	for (int i = 0; i < a.size(); i++) {
		m[stoi(a[i])] = 1;
	}

	// Process the fourth line to toggle the presence of elements in the map.
	vector<int> result;
	vector<string> b = split(lines[3], " ");
	for (int i = 0; i < b.size(); i++) {
		int n = stoi(b[i]);
		if (m.find(n) != m.end()) {
			m.erase(n);
		} else {
			m[n] = 1;
		}
	}

	// Extract the unique elements from the map and sort them.
	for (auto it = m.begin(); it != m.end(); it++) {
		result.push_back(it->first);
	}
	sort(result.begin(), result.end());

	// Print the sorted list of unique elements.
	for (int j = 0; j < result.size(); j++) {
		cout << result[j] << endl;
	}
	return 0;
}

// Split splits a string by a delimiter.
vector<string> split(string s, string delimiter) {
	vector<string> result;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		result.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	result.push_back(s);
	return result;
}

