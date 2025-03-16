
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a scanner to read input from the console
	in := bufio.NewReader(os.Stdin)

	// Reading input values for VP, VD, T, F, and C
	VP, _ := strconv.ParseFloat(read(in), 64) // Velocity of the person
	VD, _ := strconv.ParseFloat(read(in), 64) // Velocity of the dog
	T, _ := strconv.ParseFloat(read(in), 64)   // Initial time before the dog starts chasing
	F, _ := strconv.ParseFloat(read(in), 64)   // Time taken for the dog to return to the person
	C, _ := strconv.ParseFloat(read(in), 64)   // Distance the person needs to cover

	// If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
	if VD <= VP {
		fmt.Println(0) // Output 0 as the dog will never catch the person
		return           // Exit the program
	}

	answer := 0 // Initialize the number of times the dog catches up
	start := T  // Start time for the first chase

	// Loop to calculate how many times the dog can catch the person
	for {
		// Calculate the distance the person covers before the dog catches up
		x := start * VP / (VD - VP)

		// Check if the distance covered by the person is greater than or equal to C
		if (start+x)*VP >= C {
			break // Exit the loop if the person has covered the required distance
		}

		// Update the start time for the next chase
		start += 2*x + F // Add the time taken for the dog to return and the time to catch up
		answer++          // Increment the count of catches
	}

	// Output the total number of times the dog catches the person
	fmt.Println(answer)
}

func read(in *bufio.Reader) string {
	str, _ := in.ReadString('\n')
	return str
}

