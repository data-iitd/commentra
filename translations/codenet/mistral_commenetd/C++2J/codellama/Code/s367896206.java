
import java.util.Scanner;

// Define a class named Cube with a public array 'f' of size 6
class Cube {
	int f[];				// Initialize an integer array 'f' of size 6
	Cube() {
		f = new int[6];			// Initialize the array 'f'
	}
	void roll_z() { roll(1, 2, 4, 3); }	// Function to roll the cube along z-axis
	void roll_y() { roll(0, 2, 5, 3); }	// Function to roll the cube along y-axis
	void roll_x() { roll(0, 1, 5, 4); }	// Function to roll the cube along x-axis
	void roll(int i, int j, int k, int l) {	// Function to roll the cube in a specific direction
		int t = f[i];				// Swap the values of 'f[i]' and 'f[j]'
		f[i] = f[j];
		f[j] = t;				// Swap the values of 'f[j]' and 't'
	}
}

// Function to check if two cubes are equal
boolean eq(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++)	// Iterate through each element of the first cube 'c1'
		if (c1.f[i] != c2.f[i])	// If any element is not equal, return false
			return false;
	return true;			// If all elements are equal, return true
}

// Function to check if two cubes are equal after rolling
boolean equal(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++) {	// Iterate through each rolling direction for the first cube 'c1'
		for (int j = 0; j < 4; j++) {	// Iterate through each rolling step in the current direction
			if (eq(c1, c2))	// If the cubes are equal, return true
				return true;
			c1.roll_z();	// Roll the cube along z-axis
		}
		if (i % 2 == 0)c1.roll_y();	// Roll the cube along y-axis if the current index 'i' is even
		else c1.roll_x();		// Roll the cube along x-axis if the current index 'i' is odd
	}
	return false;			// If the cubes are not equal after all rolling directions and steps, return false
}

// Main function to read the cubes' states and compare them
public static void main(String[] args) {
	Cube c1 = new Cube();		// Initialize an empty cube 'c1'
	Cube c2 = new Cube();		// Initialize an empty cube 'c2'

	// Read the states of the cubes from the standard input
	Scanner sc = new Scanner(System.in);
	for (int i = 0; i < 6; i++)c1.f[i] = sc.nextInt();
	for (int i = 0; i < 6; i++)c2.f[i] = sc.nextInt();

	// Compare the cubes and print the result
	if (equal(c1, c2))System.out.println("Yes");
	else System.out.println("No");

	sc.close();			// Close the scanner
}

