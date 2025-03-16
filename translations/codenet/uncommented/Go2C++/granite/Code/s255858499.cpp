
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	int a = stoi(line);
	getline(cin, line);
	int b = stoi(line);

	if (a * b % 2!= 0) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}
	return 0;
}

