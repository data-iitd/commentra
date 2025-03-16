
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables a, b, c, and d of type int
	var a, b, c, d int

	// Create a new scanner to read values from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read values of variables a, b, c, and d from standard input
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

	// Calculate the difference between a and c, and the difference between b and d
	difference_ab := int64(a) - int64(c)
	difference_cd := int64(b) - int64(d)

	// Multiply the differences and print the result to standard output
	fmt.Println(difference_ab * difference_cd)
}

