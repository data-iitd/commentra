
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read a line from standard input and remove trailing whitespace
func rs() string {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	return s[:len(s)-1]
}

// Function to read an integer from standard input
func ri() int {
	s := rs()
	r := 0
	for _, c := range s {
		r = r*10 + int(c-'0')
	}
	return r
}

// Function to read a line from standard input and return a list of strings
func rs_() []string {
	s := rs()
	return strings.Split(s, " ")
}

// Function to read a line from standard input and return a list of integers
func ri_() []int {
	s := rs_()
	r := make([]int, len(s))
	for i := range s {
		r[i] = int(s[i])
	}
	return r
}

func main() {
	// Read the integer N from input
	N := ri()

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Loop through each integer from 1 to N (inclusive)
	for i := 1; i <= N; i++ {
		// Calculate the contribution of the current integer i to the answer
		ans += i * (N / i) * (N / i + 1) / 2
	}

	// Print the final result
	fmt.Println(ans)
}
