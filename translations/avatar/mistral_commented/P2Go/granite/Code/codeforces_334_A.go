
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare and initialize a variable 'n' with an integer value read from standard input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0])

	// Declare and initialize two variables 'i' and 'j' with initial values 1 and 'n * n' respectively
	i, j := 1, n*n

	// Start the for loop with the condition 'i < j'
	for i < j {
		// Print the current values of 'i' and 'j' on the standard output
		fmt.Println(i, j)

		// Increment the value of 'i' by 1 in each iteration of the loop
		i++

		// Decrement the value of 'j' by 1 in each iteration of the loop
		j--
	}
}

