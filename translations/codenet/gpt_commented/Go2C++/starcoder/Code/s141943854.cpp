#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	string sage;
	cin >> sage;
	if (sage == "1") {
		cout << "Hello World" << endl;
	} else if (sage == "2") {
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			int num;
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
	return 0;
}

