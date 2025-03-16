
package main

import (
	"fmt"
	"os"
)

func main() {
	var x int

	// Read an integer value from the standard input and store it in the variable x
	fmt.Fscanf(os.Stdin, "%d", &x)

	if x == 1 {
		fmt.Println(0) // If x is 1, print 0 to the standard output
	} else {
		fmt.Println(1) // Otherwise, print 1 to the standard output
	}
}

