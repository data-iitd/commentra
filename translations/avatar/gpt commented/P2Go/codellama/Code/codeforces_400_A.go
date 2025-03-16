
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input and convert it to a tuple of integers
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
func values() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read a single line of input and return a list of integers
func inlst() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read a single line of input from stdin and return a list of integers
func inlsts() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read a single integer from input
func inp() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single integer from stdin
func inps() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single line of input and return it as a string
func instr() string {
	var a string
	fmt.Scan(&a)
	return a
}

// Function to read a single line of input and return it as a list of strings
func stlst() []string {
	var a []string
	fmt.Scan(&a)
	return a
}

// Helper function to determine if a specific arrangement is possible
func help(a, b int, l []int) bool {
	tot := [][]int{}
	// Create sublists of length 'a' from the list 'l'
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}

	// Check if any combination of the sublists sums to 'b'
	for _, i := range tot {
		if sum(i) == b {
			return true
		}
	}
	return false
}

// Function to sum the elements of a list
func sum(l []int) int {
	var tot int
	for _, i := range l {
		tot += i
	}
	return tot
}

// Main function to solve the problem
func solve() {
	tot := [][]int{}
	x := instr() // Read the input string
	s := []int{}

	// Convert the input string into a list of integers (0 for 'O', 1 for 'X')
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	// Check for all divisors of 12 to find valid arrangements
	for i := 1; i < 13; i++ {
		if 12%i == 0 { // Check if 'i' is a divisor of 12
			if help(i, 12/i, s) { // Use the helper function to check arrangements
				tot = append(tot, []int{12 / i, i}) // Store valid arrangements as tuples
			}
		}
	}

	// Print the number of valid arrangements
	fmt.Println(len(tot), end=' ')

	// Print each valid arrangement in sorted order
	for _, a := range tot {
		fmt.Printf("%dx%d ", a[0], a[1])
	}
	fmt.Println() // Print a newline at the end
}

// Entry point of the program
func main() {
	// Read the number of test cases and solve each case
	for i := 0; i < inp(); i++ {
		solve()
	}
}

