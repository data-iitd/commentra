
<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
	var n, sum int

	// Step 4: Read input from the user
	fmt.Scanf("%d", &n)

	// Step 5: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) / 2

	// Step 6: Print the result
	fmt.Printf("%d\n", sum)

	// Step 7: Return from the main function
<<<<<<< HEAD
	os.Exit(0)
=======
	return
>>>>>>> 98c87cb78a (data updated)
}

