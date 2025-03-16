
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of rows/columns for the square matrix
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])

	// Initialize an empty list to store the input strings
	s := make([]string, n)

	// Read n strings from input and append them to the list s
	for i := 0; i < n; i++ {
		s[i], _ = reader.ReadString('\n')
	}

	// Initialize a flag variable (not used in this code)
	flag := 0

	// Initialize lists to store diagonal elements
	d1 := make([]string, n)  // Primary diagonal
	d2 := make([]string, n)  // Secondary diagonal

	// Initialize a set to store non-diagonal elements
	rem := make(map[string]bool)

	// Iterate through the matrix to populate the diagonals and non-diagonal elements
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If it's a primary diagonal element
			if (i == j) {
				d1[i] = string(s[i][j])
			}
			// If it's a secondary diagonal element
			if (i == n-j-1) {
				d2[i] = string(s[i][j])
			}
			// If it's a non-diagonal element
			if (i!= j && i!= n-j-1) {
				rem[string(s[i][j])] = true
			}
		}
	}

	// Check conditions to determine the output
	// If the number of unique non-diagonal elements is not 1
	if (len(rem)!= 1) {
		fmt.Println("NO")
	}
	// If the primary and secondary diagonals are not equal
	else if (d1!= d2) {
		fmt.Println("NO")
	}
	// If the primary diagonal does not consist of the same element
	else if (len(d1)!= len(set(d1))) {
		fmt.Println("NO")
	}
	// If the unique element in the primary diagonal is also in the non-diagonal set
	else if (set(d1) == rem) {
		fmt.Println("NO")
	}
	// If all conditions are satisfied, print 'YES'
	else {
		fmt.Println("YES")
	}
}

func set(s []string) map[string]bool {
	m := make(map[string]bool)
	for _, v := range s {
		m[v] = true
	}
	return m
}

