
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare four integer variables to store input values
	var a, b, c, d int

	// Create a scanner to read input values from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read input values from the user using the scanner
	for i := 0; i < 4; i++ {
		scanner.Scan()
		value, _ := strconv.Atoi(scanner.Text())
		switch i {
		case 0:
			a = value
		case 1:
			b = value
		case 2:
			c = value
		case 3:
			d = value
		}
	}

	// Check if the condition is true
	if a*b%2 == 1 && (c+d)%2 == 1 {
		// If the condition is true, print "No" to the output stream
		fmt.Println("No")
	} else {
		// If the condition is false, print "Yes" to the output stream
		fmt.Println("Yes")
	}
}

