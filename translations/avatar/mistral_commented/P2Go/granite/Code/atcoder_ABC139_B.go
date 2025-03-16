
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Get two integers from user input, separated by a space
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input)
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	b, _ := strconv.Atoi(input)

	// Initialize the variable 'hole' to 1
	hole := 1

	// Initialize the variable 'i' to 0
	i := 0

	// Initialize the variable 'check' to True
	check := true

	// Loop until the condition is not met
	for check {
		// Check if the value of 'hole' is greater than or equal to 'b'
		if hole >= b {
			// If the condition is met, set 'check' to False to terminate the loop
			check = false
		} else {
			// If the condition is not met, update the value of 'hole'
			hole = a * (i + 1) - i
			// Increment the value of 'i' by 1
			i++
		}
	}

	// Once the loop terminates, print out the value of 'i' as the result
	fmt.Println(i)
}
