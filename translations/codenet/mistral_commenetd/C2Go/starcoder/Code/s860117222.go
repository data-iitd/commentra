
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
	// Declare three long long integers to store input values
	var a, b, c int64

	// Read the values of a, b, and c from the standard input using scanf
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Calculate the difference between c and the sum of a and b
	d := c - a - b

	// Check if d is positive and if the product of the squares of a and b is less than d squared
	if d > 0 && (4 * a * b) < (d * d) {
		// If the condition is true, print "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No" to the standard output
		fmt.Println("No")
	}
}

