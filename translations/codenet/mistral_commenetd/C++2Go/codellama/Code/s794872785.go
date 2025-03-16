// Package declaration
package main

// Importing the required packages
import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
func solve() bool {
	// Initialize variables
	maxsize := 0
	maxcnt := 0
	ans_num := -1
	ans_num2 := -1
	str_v := make([]string, 0) // Vector to store strings read from input

	// Read strings from input
	var in string
	for {
		_, err := fmt.Scan(&in)
		if err != nil {
			break
		}
		// Push the string into the vector
		str_v = append(str_v, in)
		// Update maxsize if the current string is larger
		if maxsize < len(in) {
			maxsize = len(in)
			ans_num = len(str_v) - 1
		}
	}

	// Find the string with maximum occurrences in the vector
	for i := 0; i < len(str_v); i++ {
		cnt := 0
		// Count the occurrences of the current string in the vector
		for j := 0; j < len(str_v); j++ {
			if str_v[i] == str_v[j] {
				cnt++
			}
		}
		// Update maxcnt and ans_num2 if the current string has more occurrences
		if maxcnt < cnt {
			maxcnt = cnt
			ans_num2 = i
		}
	}

	// Print the answer
	fmt.Println(str_v[ans_num2], str_v[ans_num])

	// Return true to indicate successful execution
	return true
}

// Main function
func main() {
	// Set the precision of fmt.Printf to 10 decimal places
	fmt.Printf("%.10f", 1.0)
	// Call the solve function
	solve()

	// Return 0 to indicate successful execution
	os.Exit(0)
}

