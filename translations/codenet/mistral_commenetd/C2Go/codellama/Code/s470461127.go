package main

import "fmt"

func main() {
	// Declare two integer variables x and y
	var x, y int
	x = 0
	y = 0

	// Read two integers from the user using fmt.Scanf function and store them in variables x and y respectively
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	// Print the product of x and y and the sum of 2 times x and 2 times y using fmt.Printf function
	fmt.Printf("%d %d\n", x*y, (2*x) + (2*y))
}

