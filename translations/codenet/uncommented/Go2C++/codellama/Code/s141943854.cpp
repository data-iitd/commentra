
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string sage;
	cin >> sage;

	switch (stoi(sage)) {
	case 1:
		cout << "Hello World" << endl;
		break;
	case 2:
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			string num;
			cin >> num;
			sum += stoi(num);
		}
		cout << sum << endl;
		break;
	}

	return 0;
}

