
#include <iostream>

using namespace std;

int solve(int a, int b, int c) {
	int temp;
	
	if (c == a+b) {
		temp = b + c;
	} else if (c-1 > a+b) {
		temp = b + c - (c-1) + (a+b);
	} else {
		temp = b + c;
	}
	
	return temp;
}

int main() {
	int a, b, c;
	
	cin >> a >> b >> c;
	
	cout << solve(a, b, c) << endl;
	
	return 0;
}

