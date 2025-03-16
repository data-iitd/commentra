package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare two integer variables x and y
	var x, y int

	// Initialize x and y to 0
	x = 0
	y = 0

	// Read two integer values from the user and store them in x and y
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	// Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
	// Print the product and the perimeter
	fmt.Printf("%d %d\n", x*y, (2*x)+(2*y))

	// Return 0 to indicate successful completion of the program
	os.Exit(0)
}

