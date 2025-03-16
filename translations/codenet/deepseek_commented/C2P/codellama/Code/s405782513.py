#include <stdio.h>

int main(void)
{
	// Step 1: Read three integers from input.
	int c[3];
	
	while (scanf("%d %d %d", &c[0], &c[1], &c[2]) != EOF){
		// Step 2: Initialize an array to keep track of the cards.
		card = [0] * 10
		# Initialize a counter to count the number of valid cards.
		count = 0
		# Calculate the sum of the two known cards.
		sum = c[0] + c[1]
		
		# Step 3: Loop through the cards and mark them in the array.
		for i in range(3):
			card[c[i] - 1] = 1
		
		# Step 4: Check which cards can be added to the sum without exceeding 20.
		for i in range(10):
			if card[i] == 0 and sum + i + 1 <= 20:
				count += 1
		
		# Step 5: Determine if at least 4 such cards exist.
		if count >= 4:
			# Step 6: Print "YES" if such cards exist.
			print("YES")
		else:
			# Step 7: Print "NO" otherwise.
			print("NO")
	}
	
	return 0
}

