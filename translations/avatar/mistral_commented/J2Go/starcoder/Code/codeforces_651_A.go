
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new Scanner object for reading input from the standard input
	reader := bufio.NewReader ( os.Stdin )

	// Reading two integers 'a' and 'b' from the standard input
	a, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadString ( ) ) )
	b, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadString ( ) ) )

	// Initializing variable 'c' to 0
	c := 0

	// Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
	if a == 1 && b == 1 {
		fmt.Println ( 0 )
		return
	}

	// If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
	for {
		// Performing the loop until either 'a' or 'b' becomes 0
		for {
			// If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
			if a >= b {
				b++
				a -= 2
			}
			// If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
			else {
				a++
				b--
			}

			// Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
			if a <= 0 || b <= 0 {
				c++
				break
			}

			// Incrementing 'c' for each iteration of the loop
			c++
		}

		// Printing the final result 'c' as the output
		fmt.Println ( c )

		// Exiting the main function
		return
	}
}

