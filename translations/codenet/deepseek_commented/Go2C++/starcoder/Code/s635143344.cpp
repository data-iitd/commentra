#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	// Step 3: Create a vector of integers with a length of 3
	std::vector<int> in(3);
	
	// Step 4: Prompt the user to input three integers
	for (int i = 0; i < 3; i++) {
		std::cin >> in[i];
	}
	
	// Step 5: Sort the vector of integers in ascending order
	std::sort(in.begin(), in.end());
	
	// Step 6: Perform a calculation using the sorted integers and print the result
	std::cout << in[2]*10 + in[1] + in[0] << std::endl;
}

