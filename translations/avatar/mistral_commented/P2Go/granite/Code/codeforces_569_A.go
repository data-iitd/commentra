
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Prompt the user to enter three integers separated by spaces
	fmt.Print("Enter three integers separated by spaces: ")
	scanner.Scan()

	// Split the input string into three substrings and convert them to integers
	t, _ := strconv.Atoi(scanner.Text()[0:1])
	s, _ := strconv.Atoi(scanner.Text()[2:3])
	q, _ := strconv.Atoi(scanner.Text()[4:5])

	// Initialize an answer counter variable ans to 0
	ans := 0

	// Loop while the value of s is less than t
	for s < t {
		// Multiply the value of s by q and update the value of s
		s *= q

		// Increment the answer counter variable ans by 1
		ans++
	}

	// Print the final answer
	fmt.Println(ans)
}

