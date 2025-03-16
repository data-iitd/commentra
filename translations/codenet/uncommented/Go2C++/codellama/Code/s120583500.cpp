
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;

	int count = 0;
	vector<int> counter;

	if (s == "") {
		return 0;
	}
	counter.push_back(0);
	vector<string> li = split(s, "");

	for (auto s : li) {
		if (s == "A" || s == "C" || s == "G" || s == "T") {
			count++;
		} else {
			counter.push_back(count);
			count = 0;
		}
	}

	counter.push_back(count);
	sort(counter.begin(), counter.end());
	cout << counter[counter.size() - 1] << endl;

	return 0;
}

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

