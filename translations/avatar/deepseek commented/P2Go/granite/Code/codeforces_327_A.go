
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to find indices of a character in a string
func find(s string, ch byte) []int {
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

// Main block of the code
func main() {
	// Initialize the scanner
	scanner := bufio.NewScanner(os.Stdin)
	// Read the integer input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	// Read the string input and remove spaces
	scanner.Scan()
	s := strings.Replace(scanner.Text(), " ", "", -1)

	// If the string does not contain '0', print n - 1
	if!strings.ContainsRune(s, '0') {
		fmt.Println(n - 1)
	} else {
		// Find all indices of '0' in the string
		indices := find(s, '0')

		// If there is only one '0', print n
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			// Initialize maximum to 0
			maximum := 0
			// Generate all combinations of two indices of '0'
			combs := make([][]int, 0)
			for i := 0; i < len(indices)-1; i++ {
				for j := i + 1; j < len(indices); j++ {
					combs = append(combs, []int{indices[i], indices[j]})
				}
			}

			// Iterate over each combination and calculate the maximum distance
			for _, x := range combs {
				maximum = int(math.Max(float64(maximum), float64(2+2*(math.Abs(float64(indices[0]-x[0]))-1) - (math.Abs(float64(x[0]-x[1]))-1))))
			}

			// Print the count of '1's plus the maximum distance
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

