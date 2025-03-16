#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int ret = a + b;

	if (ret < (a - b)) {
		ret = a - b;
	}
	if (ret < (a * b)) {
		ret = a * b;
	}

	cout << ret << endl;
}

