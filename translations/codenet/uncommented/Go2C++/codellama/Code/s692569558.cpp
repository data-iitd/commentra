#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string ds;
	getline(cin, ds);
	getline(cin, ds);

	stringstream ss(ds);
	string d;
	vector<int> dn;
	while (ss >> d) {
		dn.push_back(stoi(d));
	}

	int sum = 0;
	for (int i = 0; i < dn.size(); i++) {
		for (int j = i + 1; j < dn.size(); j++) {
			sum += dn[i] * dn[j];
		}
	}

	cout << sum << endl;

	return 0;
}

