
#include <iostream>

using namespace std;

int main(void) {
	int n, sum;
	
	// Step 4: Read input from the user
	cin >> n;
	
	// Step 5: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) / 2;
	
	// Step 6: Print the result
	cout << sum << endl;
	
	// Step 7: Return from the main function
	return 0;
}

