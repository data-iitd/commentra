<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read four integers from the standard input
	a, _ := strconv.Atoi(os.Args[1])
	b, _ := strconv.Atoi(os.Args[2])
	c, _ := strconv.Atoi(os.Args[3])
	d, _ := strconv.Atoi(os.Args[4])

	// Check if the product of a and b is odd and if the sum of c and d is also odd
	if (a*b)%2 == 1 && (c+d)%2 == 1 {
		// If both conditions are true, print "No"
		fmt.Println("No")
	} else {
		// Otherwise, print "Yes"
		fmt.Println("Yes")
	}
}

