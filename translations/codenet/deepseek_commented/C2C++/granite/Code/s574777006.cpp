
#include <iostream>  // Include the standard input-output header

int main() {
	
	int n, i, j, q, x[10000], y[500], sum = 0;  // Declare variables
	
	std::cin >> n;  // Read the number of elements
	
	for(i = 0; i < n; i++) {
		std::cin >> x[i];  // Read the elements of array x
	}
	
	std::cin >> q;  // Read the number of queries
	
	for(i = 0; i < q; i++) {
		std::cin >> y[i];  // Read the elements of array y
	}
	
	for(i = 0; i < q; i++) {  // For each query
		for(j = 0; j < n; j++) {  // Check each element in array x
			if(y[i] == x[j]) {  // If the query matches an element in x
				sum = sum + 1;  // Increment the sum
				break;  // Break out of the inner loop
			}
		}
	}
	
	std::cout << sum << std::endl;  // Print the sum of matches
	
	return 0;  // Return 0 to indicate successful execution
}

