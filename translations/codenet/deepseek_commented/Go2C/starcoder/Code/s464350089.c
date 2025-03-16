
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the initial height `h` and the number of attacks `n`
	int h = atoi(next());
	int n = atoi(next());

	// Initialize a variable to keep track of the total damage dealt
	int a = 0;

	// Read each attack's damage and accumulate the total damage
	for (int i = 0; i < n; i++) {
		a += atoi(next());
	}

	// Check if the total damage is greater than or equal to the initial height
	if (h > a) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
}

