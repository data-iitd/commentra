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
	var x, y int
	x = 0
	y = 0

	// Read two integers from the standard input and store them in x and y
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	// Calculate the product of x and y
	// Also, calculate the perimeter of a rectangle with sides x and y
	fmt.Printf("%d %d\n", x*y, (2*x)+(2*y))
}

