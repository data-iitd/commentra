
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare four integer variables to store user input
	var a, b, c, d int

	// Create a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read four integers from the standard input
	for i := 0; i < 4; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		switch i {
		case 0:
			a = num
		case 1:
			b = num
		case 2:
			c = num
		case 3:
			d = num
		}
	}

	// Check if the product of a and b is odd and if the sum of c and d is also odd
	if a*b%2 == 1 && (c+d)%2 == 1 {
		// If both conditions are true, print "No"
		fmt.Println("No")
	} else {
		// Otherwise, print "Yes"
		fmt.Println("Yes")
	}
}
