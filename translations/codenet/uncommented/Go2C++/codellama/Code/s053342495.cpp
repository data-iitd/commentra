#include <iostream>

using namespace std;

int main() {
	int day;
	cin >> day;

	switch (day) {
	case 25:
		cout << "Christmas" << endl;
		break;
	case 24:
		cout << "Christmas Eve" << endl;
		break;
	case 23:
		cout << "Christmas Eve Eve" << endl;
		break;
	case 22:
		cout << "Christmas Eve Eve Eve" << endl;
		break;
	}

	return 0;
}

