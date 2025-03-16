<<<<<<< HEAD

import "fmt"
=======
package main

import (
	"fmt"
	"os"
	"strconv"
)
>>>>>>> 98c87cb78a (data updated)

func main() {
	// Declare an integer variable to store the input value.
	var x int

	// Read an integer input from the user and store it in the variable x.
	fmt.Scanf("%d", &x)

	// Check the value of x and print 1 or 0 based on the value of x.
	if x == 0 {
		fmt.Println("1")
	}
	if x == 1 {
		fmt.Println("0")
	}
<<<<<<< HEAD
=======

	// Return 0 to indicate successful execution of the program.
	os.Exit(0)
>>>>>>> 98c87cb78a (data updated)
}

