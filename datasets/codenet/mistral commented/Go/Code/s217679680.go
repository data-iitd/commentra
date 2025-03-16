
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Initialize a scanner for reading input from stdin
var stdin = bufio.NewScanner(os.Stdin)

// Function to read an array of integers from stdin and return it
func scanArrayInt() []int {
	// Initialize an empty slice to store the integers
	var ret = []int{}
	// Read the input line from stdin
	stdin.Scan()
	// Split the input line by space
	input := strings.Split(stdin.Text(), " ")
	// Iterate through each element in the input slice and convert it to integer
	for _, s := range input {
		// Convert the string to integer and append it to the slice
		i, _ := strconv.Atoi(s)
		ret = append(ret, i)
	}
	// Return the slice of integers
	return ret
}

// Function to initialize variables and start the main logic
func main() {
	// Read the array of integers from stdin
	arr := scanArrayInt()
	// Initialize variables a and b with the first two elements of the array
	a, b := arr[0], arr[1]
	// Initialize variables tap and consent with default values
	tap, consent := 0, 1
	// Loop until consent is greater than or equal to b
	for consent < b {
		// Increment consent by the sum of a and consent minus one
		consent = consent + a - 1
		// Increment tap by one for each iteration
		tap++
	}
	// Print the result, i.e., the number of taps required
	fmt.Println(tap)
}

