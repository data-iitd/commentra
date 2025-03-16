#######
// Code
#######

// Importing necessary libraries
import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Defining constants
const (
	mod = 1e9 + 7
)

// Function to read a single line from standard input as a list of strings
func LS( ) []string {
	s, _ := os.Stdin.ReadString( )
	return strings.Split(s[:len(s)-1], " ")
}

// Function to read a single integer from standard input
func I( ) int {
	i, _ := strconv.Atoi(LS()[0])
	return i
}

// Function to read a single float from standard input
func F( ) float64 {
	f, _ := strconv.ParseFloat(LS()[0], 64)
	return f
}

// Function to read a single string from standard input
func S( ) string {
	return LS()[0]
}

// Function to print a string with a newline character at the end
func pf(s string) {
	fmt.Println(s)
}

// Main function
func main( ) {
	// Reading input string and number of occurrences of '1' required
	s := S( )
	k := I( )

	// Finding the length of the substring consisting only of '1's
	l := 0
	for _, c := range s {
		if c!= '1' {
			// If the length of the substring is greater than or equal to the required number of occurrences, return 1
			if l >= k {
				pf("1")
				return
			}
			break
		}
		l += 1

	}

	// If the length of the substring is less than the required number of occurrences, return the character after the substring
	pf(string(s[l]))
}

// Calling the main function and printing the result
func main( ) {
	main( )
	fmt.Scan( )
}

