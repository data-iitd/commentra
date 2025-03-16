#include<iostream>

// Declare variables
int i, j, x[10000];

int main(void)
{
	// Initialize array x with zeros
	for(i=0;i<10000;i++){
		x[i] = 0;
		// Comment explaining what the loop does
		// This loop initializes all elements of the array x with zero
	}

	i = 0;
	// Read the first integer input and store it in the array x at index i
	std::cin >> x[i];
	// Comment explaining what the line does
	// Read the first integer input and store it in the array x

	// Read remaining integers and store them in the array x
	while(x[i] != 0){
		i++;
		std::cin >> x[i];
		// Comment explaining what the loop does
		// This loop reads and stores the remaining integers in the array x
	}

	// Print the results
	for(j=0;j<i;j++){
		std::cout << "Case " << j+1 << ": " << x[j] << std::endl;
		// Comment explaining what the loop does
		// This loop prints the results for each input integer
	}

	// Signal successful termination of the program
	return 0;
}

