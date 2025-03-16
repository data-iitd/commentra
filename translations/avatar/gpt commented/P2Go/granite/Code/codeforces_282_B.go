
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the first line of input which indicates the number of iterations
	firstline, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Initialize total to keep track of the accumulated value
	total := 0

	// Create an empty list to store the memory of actions taken
	memory := []string{}

	// Loop through the range defined by firstline
	for x := 0; x < firstline; x++ {
		// Read two integers A and G from input, separated by space
		A, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])
		G, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

		// Check if adding A to total does not exceed the limit of 500
		if total+A <= 500 {
			// If within limit, add A to total
			total += A
			// Record the action "A" in memory
			memory = append(memory, "A")
		} else {
			// If limit exceeded, subtract G from total
			total -= G
			// Record the action "G" in memory
			memory = append(memory, "G")
		}
	}

	// Print the sequence of actions taken as a single string
	fmt.Println(memory)
}
