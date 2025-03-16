package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare three integer variables a, b, and c
	var a, b, c int

	// Read three integers from user input
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Check if b is greater than the product of a and c
	if b > a*c {
		// If true, print the value of c
		fmt.Println(c)
	} else {
		// If false, print the result of b divided by a
		fmt.Println(b/a)
	}

	// Return 0 to indicate successful execution of the program
	os.Exit(0)
}

