
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

// Function to check for errors and exit with error message if any
func check(e error) {
	if e != nil {
		log.Fatalf("error: %v", e)
	}
}

// Main function
func main() {
	// Initialize a scanner to read from standard input
	stdin := bufio.NewScanner(os.Stdin)

	// Read the first line from standard input
	stdin.Scan()

	// Store the first line in a variable named 'sage'
	sage := stdin.Text()

	// Use a switch statement to determine the action based on the first line read
	switch sage {
	case "1":
		// Print "Hello World" if the first line is "1"
		fmt.Println("Hello World")
	case "2":
		// Initialize a variable named 'sum' to store the sum of two numbers
		var sum int

		// Use a for loop to read and sum two numbers
		for i := 0; i < 2; i++ {
			// Read the next line from standard input
			stdin.Scan()

			// Convert the next line to an integer and store it in a variable named 'num'
			num, err := strconv.Atoi(stdin.Text())

			// Check for errors and exit with error message if any
			check(err)

			// Add the current number to the sum
			sum += num
		}

		// Print the sum of the two numbers
		fmt.Println(sum)
	}
}

// End of code
