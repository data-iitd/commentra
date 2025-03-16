
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
func main() {
	for {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		if a == 0 && b == 0 {
			break
		}
		if b < a {
			a, b = b, a
		}
		fmt.Printf("%d %d\n", a, b)
	}
=======
func swap(a *int, b *int) {
	// Function to swap two integers passed by reference
	tmp := *a
	// Declare a temporary variable to store the value of 'a'

	*a = *b
	// Assign the value of 'b' to 'a'

	*b = tmp
	// Assign the value of 'a' to 'b'
}

func main() {
	// Declare two integer variables 'a' and 'b'
	var a, b int

	for {
		// Infinite loop to read two integers from the user

		fmt.Scanf("%d %d", &a, &b)
		// Read two integers from the user and store them in 'a' and 'b' respectively

		if a == 0 && b == 0 {
			break
			// If both 'a' and 'b' are zero, break out of the loop
		}

		if b < a {
			swap(&a, &b)
			// If 'b' is less than 'a', swap their values
		}

		fmt.Printf("%d %d\n", a, b)
		// Print the swapped values of 'a' and 'b'
	}
	// Return 0 to indicate successful execution of the program

	os.Exit(0)
>>>>>>> 98c87cb78a (data updated)
}

