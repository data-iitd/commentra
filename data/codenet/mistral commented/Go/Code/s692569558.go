
package main

import (
	"bufio" // Import bufio package for reading from standard input
	"fmt"   // Import fmt package for printing output
	"os"    // Import os package for interacting with operating system
	"strconv" // Import strconv package for converting strings to integers
	"strings" // Import strings package for string manipulation
)

func main() {
	// Initialize a new scanner for reading from standard input
	s := bufio.NewScanner(os.Stdin)

	// Read the first two lines from standard input and store them in the scanner
	s.Scan()
	s.Scan()

	// Assign the text of the second line to the variable ds
	ds := s.Text()

	// Split the string ds into an array of strings dd using the strings.Split function
	dd := strings.Split(ds, " ")

	// Create a new slice dn of length len(dd) and initialize each element to 0 using make function
	dn := make([]int, len(dd))

	// Iterate through each element i in the slice dd and convert its string value to integer using strconv.Atoi function and store it in the corresponding index of slice dn
	for i, d := range dd {
		dn[i], _ = strconv.Atoi(d)
	}

	// Initialize sum variable to 0
	sum := 0

	// Iterate through each index i in the slice dn
	for i := 0; i < len(dn); i++ {
		// Iterate through each index j greater than i in the slice dn
		for j := i + 1; j < len(dn); j++ {
			// Add the product of dn[i] and dn[j] to the sum variable
			sum += dn[i] * dn[j]
		}
	}

	// Print the value of sum variable to the standard output using fmt.Println function
	fmt.Println(sum)

	// End of code
}