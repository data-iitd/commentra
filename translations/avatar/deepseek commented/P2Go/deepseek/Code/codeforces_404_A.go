package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Scan(&n)  // Take the size of the square matrix as input
	s := []string{}  // Initialize an empty list to store the matrix elements

	// Take n inputs, each representing a row of the matrix, and append these to the list s
	for i := 0; i < n; i++ {
		k, _ := reader.ReadString('\n')
		s = append(s, k[:len(k)-1])  // Remove the newline character
	}

	flag := 0  // Initialize flag to 0
	d1 := []rune{}  // Initialize an empty list to store the diagonal elements from top-left to bottom-right
	d2 := []rune{}  // Initialize an empty list to store the diagonal elements from top-right to bottom-left
	rem := map[rune]bool{}  // Initialize a set to store the non-diagonal elements

	// Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
				d1 = append(d1, rune(s[i][j]))
			}
			if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
				d2 = append(d2, rune(s[i][j]))
			}
			if (i != j && i != n - j - 1) {  // Check if the element is not on the diagonals
				rem[rune(s[i][j])] = true
			}
		}
	}

	// Check the conditions and print 'NO' or 'YES' based on the conditions
	if (len(rem) != 1) {
		fmt.Println("NO")  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
	} else if (string(d1) != string(d2)) {
		fmt.Println("NO")  // Print 'NO' if the two diagonals are not equal
	} else if (len(rem) != 1) {
		fmt.Println("NO")  // Print 'NO' if the diagonal elements do not all have the same value
	} else if (string(d1) == string(rem)) {
		fmt.Println("NO")  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
	} else {
		fmt.Println("YES")  // Print 'YES' if all conditions are met
	}
