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
	// Declare three integer variables to store user input
	var a, b, c int

	// Read three integers from the standard input
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Check if the sum of a and b is greater than or equal to c
	if a+b >= c {
		// If true, print "Yes"
		fmt.Println("Yes")
	} else {
		// Otherwise, print "No"
		fmt.Println("No")
	}
}

