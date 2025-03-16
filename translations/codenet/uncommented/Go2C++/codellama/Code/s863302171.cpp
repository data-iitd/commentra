#include <iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	
	for (int i = 0; i < 3; i++) {
		if (n[i] == '7') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}

