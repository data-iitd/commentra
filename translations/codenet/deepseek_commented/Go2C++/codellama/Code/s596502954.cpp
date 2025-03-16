
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int a, b, c;
	ss >> a >> b >> c;
	if (a + b >= c) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

