#include <iostream>

using namespace std;

int main() {
    // Declare variables for radius (r), distance (D), and initial value (x)
	int r, D, x;
    
    // Read input values for r, D, and x from the user
	cin >> r >> D >> x;

    // Loop to perform calculations and print results for 10 iterations
	for (int i = 1; i <= 10; i++) {
        // Calculate and print the result of the formula r*x - D
		cout << r*x - D << endl;
        
        // Update x for the next iteration using the formula r*x - D
		x = r*x - D;
	}
}

