package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

// check is a utility function that logs an error and exits the program if an error is encountered.
func check(e error) {
	if e != nil {
		log.Fatalf("error: %v", e)
	}
}

func main() {
	// Create a new scanner to read input from standard input (stdin).
	stdin := bufio.NewScanner(os.Stdin)
	
	// Read the first line of input.
	stdin.Scan()
	sage := stdin.Text() // Store the input in the variable 'sage'.

	// Use a switch statement to handle different cases based on the input value.
	switch sage {
	case "1":
		// If the input is "1", print "Hello World".
		fmt.Println("Hello World")
	case "2":
		// If the input is "2", initialize a variable to hold the sum of two numbers.
		var sum int
		// Loop to read two numbers from input.
		for i := 0; i < 2; i++ {
			stdin.Scan() // Read the next line of input.
			num, err := strconv.Atoi(stdin.Text()) // Convert the input string to an integer.
			check(err) // Check for any conversion errors.
			sum += num // Add the number to the sum.
		}
		// Print the total sum of the two numbers.
		fmt.Println(sum)
	}
}
