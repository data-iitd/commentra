#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string ds;
	getline(cin, ds);
	getline(cin, ds);

	vector<int> dn;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i] =='') {
			continue;
		}
		int d = 0;
		while (i < ds.size() && ds[i]!='') {
			d = d * 10 + ds[i] - '0';
			i++;
		}
		dn.push_back(d);
	}

	int sum = 0;
	for (int i = 0; i < dn.size(); i++) {
		for (int j = i + 1; j < dn.size(); j++) {
			sum += dn[i] * dn[j];
		}
	}

	cout << sum << endl;
}

