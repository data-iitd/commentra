
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Main function starts here
func main() {
	// Declare and initialize variables
	n := 0

	// Read an integer value from the user
	fmt.Print("Enter the number of integers: ")
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(input)

	cnt4 := 0 // Initialize counter for 4's multiples
	cnt2 := 0 // Initialize counter for 2's multiples

	// Iterate through each integer input
	for i := 0; i < n; i++ {
		wk := 0 // Declare and initialize a variable to store the current integer input

		// Read an integer value from the user
		fmt.Print("Enter an integer: ")
		input, _ := reader.ReadString('\n')
		wk, _ = strconv.Atoi(input)

		// Check if the current integer is a multiple of 4
		if wk%4 == 0 {
			cnt4++ // Increment the counter for 4's multiples
		} else if wk%2 == 0 {
			cnt2++ // Increment the counter for 2's multiples
		}
	}

	// Check the condition to determine the output
	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes") // Output "Yes" if the condition is true
	} else {
		fmt.Println("No") // Output "No" if the condition is false
	}

	// Main function ends here
}

