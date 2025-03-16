package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	inf = 1e20
	eps = 1.0 / 1e10
	mod = 1e9 + 7
)

var dd = [][2]int{
	{-1, 0}, {0, 1}, {1, 0}, {0, -1},
}

var ddn = [][2]int{
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},
}

// Function to read a single integer from standard input
func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	var x int
	fmt.Sscan(scanner.Text(), &x)
	return x
}

// Function to read a single string from standard input
func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

// Main function
func main() {
	scanner := bufio.NewScanner(os.Stdin)

	// Reading input string and number of occurrences of '1' required
	s := readString(scanner)
	k := readInt(scanner)

	// Finding the length of the substring consisting only of '1's
	l := 0
	for _, c := range s {
		if c != '1' {
			// If the length of the substring is greater than or equal to the required number of occurrences, return 1
			if l >= k {
				fmt.Println(1)
				return
			}
			break
		}
		l++
	}

	// If the length of the substring is less than the required number of occurrences, return the character after the substring
	if l < len(s) {
		fmt.Println(string(s[l]))
	} else {
		fmt.Println("") // If there is no character after the substring
	}
}

// <END-OF-CODE>
