#include <iostream>
#include <string>
#include <vector>

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
			int num;
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
}

