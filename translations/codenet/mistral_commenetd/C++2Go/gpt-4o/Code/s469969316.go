package main

import (
	"fmt"
	"strings"
)

func Not(x int) int { // Function to calculate NOT of a binary number
	return 2 - x
}

func And(x, y int) int { // Function to calculate AND of two binary numbers
	if x*y == 0 {
		return 0 // If product of x and y is zero, return zero
	}
	if x == 2 && y == 2 {
		return 2 // If both x and y are 2, return 2
	}
	return 1 // Otherwise, return 1
}

func Or(x, y int) int { // Function to calculate OR of two binary numbers
	if x == 2 || y == 2 {
		return 2 // If either x or y is 2, return 2
	}
	if x == 1 || y == 1 {
		return 1 // If either x or y is 1, return 1
	}
	return 0 // Otherwise, return 0
}

var it int // Index for parsing
var cnt int // Counter for valid expressions

func parse(ss string) int { // Function to parse the input string and calculate the logical expression
	c := ss[it] // Read the next character from the input string
	it++       // Increment the index
	if c >= '0' && c <= '2' {
		return int(c - '0') // If character is a binary digit, convert it to an integer and return
	}
	if c == '-' {
		return Not(parse(ss)) // If character is NOT, recursively call parse() and apply NOT
	}

	x := parse(ss) // Parse the first binary number
	c = ss[it]     // Read the next character from the input string
	it++           // Increment the index
	y := parse(ss) // Parse the second binary number
	it++           // Increment the index
	if c == '*' {
		return And(x, y) // If character is AND, call And() function
	}
	return Or(x, y) // Otherwise, call Or() function
}

func main() { // Main function
	var input string
	for {
		fmt.Scan(&input) // Read input
		if input == "." {
			break // Exit on end of input
		}
		cnt = 0 // Initialize counter for counting the number of valid expressions
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a := []int{i, j, k} // Initialize the array a with values 0, 1, 2
					ss := input        // Set the input string for the current combination
					for _, c := range ss { // Replace P, Q, R with the values of a, b, c respectively
						switch c {
						case 'P':
							ss = strings.Replace(ss, string(c), string(a[0]+'0'), 1)
						case 'Q':
							ss = strings.Replace(ss, string(c), string(a[1]+'0'), 1)
						case 'R':
							ss = strings.Replace(ss, string(c), string(a[2]+'0'), 1)
						}
					}
					it = 0 // Reset the index of the input string
					if parse(ss) == 2 { // If the logical expression is valid, increment the counter
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt) // Print the number of valid expressions for the current input
	}
}

// <END-OF-CODE>
