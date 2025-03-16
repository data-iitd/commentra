#include <stdio.h>
#include <stdlib.h>

int main() {
	// Step 3: Create a slice of integers with a length of 3
	int in[3];
	
	// Step 4: Prompt the user to input three integers
	scanf("%d %d %d", &in[0], &in[1], &in[2]);
	
	// Step 5: Sort the slice of integers in ascending order
	int i, j, temp;
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 3; j++) {
			if (in[i] > in[j]) {
				temp = in[i];
				in[i] = in[j];
				in[j] = temp;
			}
		}
	}
	
	// Step 6: Perform a calculation using the sorted integers and print the result
	printf("%d\n", in[2]*10 + in[1] + in[0]);
	
	return 0;
}
