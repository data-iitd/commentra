package main

import "fmt"

func main() {
	var a, b, x, y int

	// Step 4: Read two integer values from the user and store them in variables a and b.
	fmt.Scanf("%d%d", &a, &b)

	// Step 5: Calculate the product of a and b, and store the result in variable x.
	x = a * b

	// Step 6: Calculate the perimeter of a rectangle with sides a and b, and store the result in variable y.
	y = (a + b) * 2

	// Step 7: Display the values of x and y.
	fmt.Printf("%d %d\n", x, y)

	// Step 8: Return 0 to indicate that the program has executed successfully.
	return 0
}

