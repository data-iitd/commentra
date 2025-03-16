
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Main function
func main() {
	// Create a new buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read input from the console
	fmt.Print("Enter a number: ")
	input, _ := reader.ReadString('\n')

	// Convert the input string to an integer
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Call the'solve' function to calculate and print the result
	solve(n)
}

//'solve' function to calculate and print the result
func solve(n int) {
	// Calculate the result and print it to the console
	fmt.Println((n/3)*2 + (n%3 == 0? 0 : 1))
}

