
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare three integer variables to store user input
	var a, b, c int

	// Create a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the standard input
	for i := 0; i < 3; i++ {
		if!scanner.Scan() {
			fmt.Println("Error: Failed to read input.")
			return
		}
		var err error
		switch i {
		case 0:
			a, err = strconv.Atoi(scanner.Text())
		case 1:
			b, err = strconv.Atoi(scanner.Text())
		case 2:
			c, err = strconv.Atoi(scanner.Text())
		}
		if err!= nil {
			fmt.Println("Error: Invalid input.")
			return
		}
	}

	// Check if the sum of a and b is greater than or equal to c
	if a+b >= c {
		// If true, print "Yes"
		fmt.Println("Yes")
	} else {
		// Otherwise, print "No"
		fmt.Println("No")
	}
}

