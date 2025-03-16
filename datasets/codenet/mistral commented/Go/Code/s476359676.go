
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a scanner for reading input from stdin
var sc *bufio.Scanner

func init() {
	sc = bufio.NewScanner(os.Stdin)
	sc.Buffer(make([]byte, 0), 1000000001*3) // Buffer size is set to a large value to avoid frequent reallocations
	sc.Split(bufio.ScanWords)              // Split function is set to split input on words
}

func nextStr() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Main function to read input and process it
func main() {
	// Read the number of test cases
	n := nextInt()

	// Initialize variables for processing the input
	ans := 0
	aPrev := 0

	// Process each test case
	for i := 0; i < n; i++ {
		// Read the next integer as 'a'
		a := nextInt()

		// Check if 'a' is valid based on the conditions in the problem statement
		switch {
		case a > i || a > aPrev+1: // 'a' is not valid, print -1 and exit
			fmt.Println(-1)
			return
		case a == aPrev+1: // Increment the answer if 'a' is consecutive with the previous number
			ans++
		default: // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a
		}

		// Update the previous number
		aPrev = a
	}

	// Print the final answer
	fmt.Println(ans)

	// End of code
