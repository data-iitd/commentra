package main

import (
	"fmt"
)

func main() {
	// Reading the size of the matrix (n x n)
	var n int
	fmt.Scan(&n)

	// Initializing a 2D slice to store the matrix
	arr := make([][]rune, n)

	// Reading n strings from the input
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		arr[i] = []rune(str) // Convert string to rune slice
	}

	// Storing the first two characters of the matrix for comparison
	a := arr[0][0]
	b := arr[0][1]

	// Checking if the first two characters are the same
	if a == b {
		fmt.Println("NO") // If they are the same, print "NO"
		return
	}

	// Initializing a boolean variable to track the result
	res := true

	// Checking the conditions for the characters in the matrix
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			// Checking if the current position is on the main diagonal or the anti-diagonal
			if i == j || i+j == n-1 {
				// If it is, check if the character matches 'a'
				if arr[i][j] != a {
					res = false // If not, set result to false and break
					break
				}
			} else {
				// If it is not on the diagonals, check if the character matches 'b'
				if arr[i][j] != b {
					res = false // If not, set result to false and break
					break
				}
			}
		}
	}

	// Print "YES" if the conditions are satisfied, otherwise print "NO"
	if res {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
