
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// Read initial values for r, D, and x
	int r, D, x;
	cin >> r >> D >> x;
	
	// Loop to calculate and print the values of x for 10 iterations
	for (int i = 1; i <= 10; i++) {
		x = r*x - D;
		cout << x << endl;
	}
	
	return 0;
}

