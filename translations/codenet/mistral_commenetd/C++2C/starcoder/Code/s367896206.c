
#include<stdio.h>

// Define a structure named Cube with a public array 'f' of size 6
typedef struct {
	int f[6];				// Initialize an integer array 'f' of size 6
} Cube;

// Function to check if two cubes are equal
int eq(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++)	// Iterate through each element of the first cube 'c1'
		if (c1.f[i]!= c2.f[i])	// If any element is not equal, return false
			return 0;
	return 1;			// If all elements are equal, return true
}

// Function to check if two cubes are equal after rolling
int equal(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++) {	// Iterate through each rolling direction for the first cube 'c1'
		for (int j = 0; j < 4; j++) {	// Iterate through each rolling step in the current direction
			if (eq(c1, c2))	// If the cubes are equal, return true
				return 1;
			roll(c1, 1, 2, 4, 3);	// Roll the cube along z-axis
		}
		if (i % 2 == 0)roll(c1, 0, 2, 5, 3);	// Roll the cube along y-axis if the current index 'i' is even
		else roll(c1, 0, 1, 5, 4);		// Roll the cube along x-axis if the current index 'i' is odd
	}
	return 0;			// If the cubes are not equal after all rolling directions and steps, return false
}

// Function to roll the cube in a specific direction
void roll(Cube *c, int i, int j, int k, int l) {
	int t = c->f[i];				// Swap the values of 'c->f[i]' and 'c->f[j]'
	c->f[i] = c->f[j];
	c->f[j] = t;				// Swap the values of 'c->f[j]' and 't'
}

// Main function to read the cubes' states and compare them
int main()
{
	Cube c1, c2;			// Initialize two empty cubes 'c1' and 'c2'

	// Read the states of the cubes from the standard input
	for (int i = 0; i < 6; i++)scanf("%d", &c1.f[i]);
	for (int i = 0; i < 6; i++)scanf("%d", &c2.f[i]);

	// Compare the cubes and print the result
	if (equal(c1, c2))printf("Yes\n");
	else printf("No\n");

	return 0;
}

