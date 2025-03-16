
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
func rs ( ) string {
	s, _ := bufio.NewReader ( os.Stdin ).ReadString ( )
	return strings.TrimSuffix ( s, "\n" )
}

// Function to read a single integer from standard input
func ri ( ) int {
	i, _ := strconv.Atoi ( rs ( ) )
	return i
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
func ri_ ( ) []int {
	s := strings.Split ( rs ( ), " " )
	i := make ( []int, len ( s ) )
	for j := 0 ; j < len ( s ) ; j++ {
		i [ j ], _ = strconv.Atoi ( s [ j ] )
	}
	return i
}

func main ( ) {
	// Read the number of test cases from standard input
	N := ri ( )

	// Initialize the answer to 0
	ans := 0

	// Iterate through all numbers from 1 to N
	for i := 1 ; i <= N ; i++ {
		// Calculate the contribution of i to the answer
		// The formula is given by the problem statement
		ans += i * ( N / i ) * ( N / i + 1 ) / 2
	}

	// Print the answer
	fmt.Println ( ans )
}

