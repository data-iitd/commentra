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
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			count++;
		} else {
			counter.push_back(count);
			count = 0;
		}
	}
	counter.push_back(count);
	sort(counter.begin(), counter.end());
	cout << counter[counter.size() - 1] << endl;
}

