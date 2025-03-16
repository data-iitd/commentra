package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	inf = 1e20
	eps = 1e-10
	mod = 1e9 + 7
)

var dd = [][2]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}} // Directions for movement in a grid (up, right, down, left)
var ddn = [][2]int{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}} // Directions for movement in a grid with diagonals

// Functions to read input more efficiently
func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func readString() string {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	return s[:len(s)-1] // Remove the newline character
}

func main() {
	s := readString() // Read the input string
	k := readInt()    // Read the integer k
	l := 0            // Initialize a counter for leading '1's

	for _, c := range s { // Loop through each character in the string
		if c != '1' { // Check if the character is not '1'
			break // Exit the loop if a non-'1' character is found
		}
		l++ // Increment the counter for each '1' found
	}

	if l >= k { // Check if the number of leading '1's is greater than or equal to k
		fmt.Println(1) // Print 1 if true
		return
	}
	fmt.Println(string(s[l])) // Print the character at the position of the first non-'1' character
}

// <END-OF-CODE>
