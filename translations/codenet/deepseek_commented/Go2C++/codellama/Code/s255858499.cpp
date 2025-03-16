
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int a_int = stoi(a);
	int b_int = stoi(b);
	if (a_int * b_int % 2 != 0) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}
	return 0;
}

