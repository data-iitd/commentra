
#include <iostream>

int main(void)
{
	// Step 1: Read three integers from input.
	int c[3];
	
	while (std::cin >> c[0] >> c[1] >> c[2]){
		// Step 2: Initialize an array to keep track of the cards.
		char card[10] = {0};
		int i;
		// Initialize a counter to count the number of valid cards.
		int count = 0;
		// Calculate the sum of the two known cards.
		int sum = c[0] + c[1];
		
		// Step 3: Loop through the cards and mark them in the array.
		for (i = 0; i < 3; i++){
			card[c[i] - 1] = 1;
		}
		
		// Step 4: Check which cards can be added to the sum without exceeding 20.
		for (i = 0; i < 10; i++){
			if (card[i] == 0 && sum + i + 1 <= 20){
				count++;
			}
		}
		
		// Step 5: Determine if at least 4 such cards exist.
		if (count >= 4){
			// Step 6: Print "YES" if such cards exist.
			std::cout << "YES" << std::endl;
		}
		else {
			// Step 7: Print "NO" otherwise.
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}
