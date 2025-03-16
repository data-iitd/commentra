
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

func main() {
	var n, k, x, y, z int
	// Declare five integer variables: n, k, x, y, and z

	fmt.Scanf("%d", &n)
	// Use the fmt.Scanf() function to read the first integer (n) from the standard input stream

	fmt.Scanf("%d", &k)
	// Use the fmt.Scanf() function to read the second integer (k) from the standard input stream

	x = n / k
	// Calculate the integer division of n by k and assign the result to the variable x

	y = n % k
	// Calculate the remainder of n divided by k and assign the result to the variable y

	if y!= 0 {
		z = x + 1 - x
		// If the remainder y is non-zero, assign the value 1 to the variable z
	} else {
		z = x - x
		// If the remainder y is zero, assign the value 0 to the variable z
	}
	fmt.Printf("%d\n", z)
	// Use the fmt.Printf() function to print the value of z to the standard output stream
<<<<<<< HEAD

	os.Exit(0)
	// Return 0 to indicate successful execution of the program
=======
>>>>>>> 98c87cb78a (data updated)
}

