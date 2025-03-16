
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input from the standard input stream
	n, m := readInput()

	// Initialize vectors's' and 'c' for storing student numbers and classes respectively
	s := make([]int, m)
	c := make([]int, m)

	// Read student numbers and classes from the standard input stream
	for i := 0; i < m; i++ {
		s[i], c[i] = readInput()
		// Decrement student numbers by 1 as they are 1-indexed
		s[i]--
	}

	// Check all strings of length 'n' for a valid combination of student numbers and classes
	for i := 0; i < 1000; i++ {
		// Convert the current number to a string
		st := strconv.Itoa(i)

		// Check if the length of the string is equal to 'n'
		if len(st)!= n {
			continue
		}

		// Initialize a flag 'f' to check if the current combination is valid
		f := 1

		// Check each combination of student number and class
		for j := 0; j < m; j++ {
			// Check if the current character in the string matches the expected class
			if st[s[j]]!= string(c[j]+'0') {
				// If no, set the flag 'f' to 0 and break the loop
				f = 0
				break
			}
		}

		// If all checks passed, print the current number and exit the program
		if f == 1 {
			fmt.Println(i)
			os.Exit(0)
		}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	}

	// If no valid combination was found, print -1
	fmt.Println(-1)
}

func readInput() (int, int) {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	return n, m
}

