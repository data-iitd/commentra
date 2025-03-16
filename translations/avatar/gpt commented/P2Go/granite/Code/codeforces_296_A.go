
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input n which represents the threshold for majority
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])

	// Read a line of input, split it into a list of strings, and store it in m
	m := strings.Split(bufio.NewReader(os.Stdin).ReadLine()[2:], " ")

	// Initialize a variable to track if a majority element is possible
	possible := true

	// Iterate through each unique element in the list m
	for i := range m {
		// Check if the count of the current element i is greater than or equal to n/2 + 1
		if strings.Count(strings.Join(m, " "), i) >= n/2+1 {
			// If it is, set possible to False and break the loop
			possible = false
			break
		}
	}

	// Print 'YES' if a majority element is not found, otherwise print 'NO'
	fmt.Println("YES")
}
