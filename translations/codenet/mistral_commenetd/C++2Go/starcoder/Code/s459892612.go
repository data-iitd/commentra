
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare and initialize three integer variables
	var a, b, c int

	// Read the values of a, b, and c from the standard input using cin
	fmt.Scanf("%d %d %d", &a, &b, &c)

<<<<<<< HEAD
	// Check if the sum of a and b is greater than or equal to c
	if a+b >= c {
		// If the condition is true, print the string "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// If the condition is false, print the string "No" to the standard output
		fmt.Println("No")
=======
	if a+b >= c { // Check if the sum of a and b is greater than or equal to c
		fmt.Println("Yes") // If the condition is true, print the string "Yes" to the standard output
	} else {
		fmt.Println("No") // If the condition is false, print the string "No" to the standard output
>>>>>>> 98c87cb78a (data updated)
	}
}

