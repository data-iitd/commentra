// Package declaration, not a logical block, no comments needed.

// Import statement, not a logical block, no comments needed.
import (
	"fmt"
)

// Function comp checks if x is less than a. If so, it returns 0, otherwise it returns 10.
public static int comp(int x, int a) {
	// If x is less than a, return 0, otherwise return 10.
	if (x < a) {
		return 0;
	}

	// If x is not less than a, return 10.
	return 10;
}

// Main function initializes two integer variables x and a, reads their values from the standard input,
// and then prints the result of calling the comp function with these values.
public static void main(String[] args) {
	int x, a;
	Scanner sc = new Scanner(System.in);
	x = sc.nextInt();
	a = sc.nextInt();
	System.out.println(comp(x, a));
}

