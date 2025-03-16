<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare two integer variables x and y
	var x, y int

	// Read two integers from the user using fmt.Scanf function and store them in variables x and y respectively
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)

	// Print the product of x and y and the sum of 2 times x and 2 times y using fmt.Printf function
	fmt.Printf("%d %d\n", x*y, (2*x)+(2*y))

	// Return 0 to indicate successful execution of the program
	os.Exit(0)
}

=======
package main

import "fmt"

func main() {
	var x, y int
	fmt.Scanf("%d", &x)
	fmt.Scanf("%d", &y)
	fmt.Printf("%d %d\n", x*y, (2*x) + (2*y))
}
>>>>>>> 98c87cb78a (data updated)
