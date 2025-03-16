
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> ns;
	string line;
	getline(cin, line);
	stringstream ss(line);
	int n;
	while (ss >> n) {
		ns.push_back(n);
	}
	sort(ns.begin(), ns.end());
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

