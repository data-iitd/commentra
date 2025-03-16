package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of rows/columns for the square matrix
	var n int
	fmt.Fscan(reader, &n)
	
	// Initialize an empty list to store the input strings
	s := make([]string, n)
	
	// Read n strings from input and append them to the list s
	for i := 0; i < n; i++ {
		k, _ := reader.ReadString('\n')
		s[i] = k[:len(k)-1] // Remove the newline character
	}
	
	// Initialize a flag variable (not used in this code)
	var flag bool
	
	// Initialize lists to store diagonal elements
	d1 := []rune{} // Primary diagonal
	d2 := []rune{} // Secondary diagonal
	
	// Initialize a map to store non-diagonal elements
	rem := make(map[rune]bool)
	
	// Iterate through the matrix to populate the diagonals and non-diagonal elements
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// If it's a primary diagonal element
			if i == j {
				d1 = append(d1, rune(s[i][j]))
			}
			// If it's a secondary diagonal element
			if i == n - j - 1 {
				d2 = append(d2, rune(s[i][j]))
			}
			// If it's a non-diagonal element
			if i != j && i != n - j - 1 {
				rem[rune(s[i][j])] = true
			}
		}
	}
	
	// Check conditions to determine the output
	// If the number of unique non-diagonal elements is not 1
	if len(rem) != 1 {
		fmt.Println("NO")
	// If the primary and secondary diagonals are not equal
	} else if string(d1) != string(d2) {
		fmt.Println("NO")
	// If the primary diagonal does not consist of the same element
	} else if len(map[rune]bool(d1)) != 1 {
		fmt.Println("NO")
	// If the unique element in the primary diagonal is also in the non-diagonal set
	} else if map[rune]bool(d1) == rem {
		fmt.Println("NO")
	// If all conditions are satisfied, print 'YES'
	} else {
		fmt.Println("YES")
	}
}
