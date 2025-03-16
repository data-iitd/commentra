
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize three integer variables 'a', 'b', and 'c'
	a, b, c := 0, 0, 0

	// Create a new scanner to read values from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read values of 'a', 'b', and 'c' from the standard input
	for scanner.Scan() {
		text := scanner.Text()
		if i, err := strconv.Atoi(text); err == nil {
			switch a {
			case 0:
				a = i
			case 1:
				b = i
			case 2:
				c = i
			}
		}
	}

	// Check if the given condition is true
	if (100*a + 10*b + c) % 4 == 0 {
		// If the condition is true, print 'YES' to the standard output
		fmt.Println("YES")
	} else {
		// If the condition is false, print 'NO' to the standard output
		fmt.Println("NO")
	}
}
