#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int tap = 0;
	int consent = 1;
	while (consent < b) {
		consent += a - 1;
		tap++;
	}
	cout << tap << endl;
}

