package main // Step 1: Define the main package.

import ( // Step 2: Import the necessary packages.
	"fmt" // For formatted I/O.
)

func main() { // Step 3: Define the main function.
	var a, b, h int // Step 4: Declare three integer variables a, b, and h.

	// Step 5: Read three integer values from the user and store them in a, b, and h.
	fmt.Scanf("%d%d%d", &a, &b, &h)

	// Step 6: Calculate the area of a trapezoid using the formula (a+b)*h/2 and print the result.
	fmt.Println((a + b) * h / 2)

	// Step 7: End the main function.
} // <END-OF-CODE>
