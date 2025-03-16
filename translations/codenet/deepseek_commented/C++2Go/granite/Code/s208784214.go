
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Initialize variables
	// We declare two integer variables, N and A, to store user input.
	var N, A int

	// Step 2: Read input values
	// We create a scanner to read input from the standard input.
	// We read two integer values from the scanner and store them in variables N and A.
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}
	if scanner.Scan() {
		A, _ = strconv.Atoi(scanner.Text())
	}

	// Step 3: Perform the required operation
	// We check if the remainder of N divided by 500 is less than or equal to A.
	// If the condition is true, we print "Yes"; otherwise, we print "No".
	if N%500 <= A {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

	// Step 4: Return from the main function
	// We return 0 to indicate successful execution of the program.
}

