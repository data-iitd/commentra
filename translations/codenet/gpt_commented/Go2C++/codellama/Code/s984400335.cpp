
#include <iostream>

using namespace std;

int min(int nums[], int size) {
	int min = nums[0];
	for (int i = 1; i < size; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	cout << min({n*a, b}) << endl;
	return 0;
}

