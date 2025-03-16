

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	h, _ := reader.ReadString('\n')
	h = h[:len(h)-1]
	// Read a line from the standard input and remove the trailing newline character
	// Assign the resulting string to the variable h

	a, _ := reader.ReadString('\n')
	a = a[:len(a)-1]
	// Read a line from the standard input and remove the trailing newline character
	// Assign the resulting string to the variable a

	h_int, _ := strconv.Atoi(h)
	// Convert the string h to an integer and assign the result to the variable h_int

	a_int, _ := strconv.Atoi(a)
	// Convert the string a to an integer and assign the result to the variable a_int

	sho := h_int / a_int
	// Calculate the quotient of h_int by a_int and assign the result to the variable sho

	am := h_int % a_int
	// Calculate the remainder of the division of h_int by a_int and assign the result to the variable am

	if am!= 0 {
	// Check if the remainder is equal to zero
	// If not, execute the following block of code

	 sho += 1
	// Increment the value of the variable sho by one
	}

	fmt.Println(sho)
	// Print the value of the variable sho
}
