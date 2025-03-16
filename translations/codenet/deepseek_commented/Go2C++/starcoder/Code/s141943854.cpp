
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

int main() {
	string sage;
	cin >> sage;

	switch (sage) {
	case "1":
		cout << "Hello World" << endl;
	case "2":
		int sum = 0;
		for (int i = 0; i < 2; i++) {
			cin >> sage;
			int num = atoi(sage.c_str());
			sum += num;
		}
		cout << sum << endl;
	}
}

