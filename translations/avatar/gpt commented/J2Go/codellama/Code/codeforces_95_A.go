package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new Scanner object to read input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of strings
	var n int
	sc.Scan()
	fmt.Sscan(sc.Text(), &n)

	// Read each string and convert it to a character array
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		ss[i] = []rune(sc.Text())
	}

	// Read the character array to be modified
	sc.Scan()
	cc := []rune(sc.Text())
	m := len(cc)

	// Read the character to be replaced
	sc.Scan()
	c := rune(sc.Text()[0])
	c_ := strings.ToUpper(string(c))[0]

	// Determine the character to replace with
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	a_ := strings.ToUpper(string(a))[0]

	// Array to track positions that can be marked as lucky
	lucky := make([]bool, m)

	// Loop through each position in the character array
	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			// Check if the substring matches and mark lucky positions
			if m-j >= l && compare(cc[j:j+l], ss[i]) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Replace characters in the original array based on lucky positions
	for j := 0; j < m; j++ {
		if lucky[j] {
			// Replace with the determined character based on case
			if strings.ToLower(string(cc[j])) == string(c) {
				cc[j] = a_
			} else {
				cc[j] = c_
			}
		}
	}

	// Print the modified character array
	fmt.Println(string(cc))
}

// Method to compare two character arrays with case insensitivity
func compare(aa, bb []rune) int {
	m := len(aa)
	for i := 0; i < m; i++ {
		// Convert characters to uppercase for comparison
		a := strings.ToUpper(string(aa[i]))[0]
		b := strings.ToUpper(string(bb[i]))[0]
		// Return the difference if characters do not match
		if a != b {
			return int(a) - int(b)
		}
	}
	// Return 0 if all characters match
	return 0
}

