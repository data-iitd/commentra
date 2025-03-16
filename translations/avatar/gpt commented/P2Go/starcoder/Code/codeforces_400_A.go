package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input and convert it to a tuple of integers
func value() (a, b int) {
	fmt.Scanf("%d %d", &a, &b)
	return
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
func values() (a, b int) {
	fmt.Fscanf(os.Stdin, "%d %d", &a, &b)
	return
}

// Function to read a single line of input and return a list of integers
func inlst() []int {
	var lst []int
	fmt.Scanf("%s", &lst)
	return lst
}

// Function to read a single line of input from stdin and return a list of integers
func inlsts() []int {
	var lst []int
	fmt.Fscanf(os.Stdin, "%s", &lst)
	return lst
}

// Function to read a single integer from input
func inp() int {
	var a int
	fmt.Scanf("%d", &a)
	return a
}

// Function to read a single integer from stdin
func inps() int {
	var a int
	fmt.Fscanf(os.Stdin, "%d", &a)
	return a
}

// Function to read a single line of input and return it as a string
func instr() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a single line of input and return it as a list of strings
func stlst() []string {
	var lst []string
	fmt.Scanf("%s", &lst)
	return lst
}

// Helper function to determine if a specific arrangement is possible
func help(a, b int, l []int) bool {
	tot := make([][]int, b)
	// Create sublists of length 'a' from the list 'l'
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}
	// Check if any combination of the sublists sums to 'b'
	for i := range tot {
		if sum(tot[i]) == b {
			return true
		}
	}
	return false
}

// Main function to solve the problem
func solve() {
	tot := make([][2]int, 0)
	x := instr()
	s := make([]int, 0)
	// Convert the input string into a list of integers (0 for 'O', 1 for 'X')
	for i := range x {
		if x[i] == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	// Check for all divisors of 12 to find valid arrangements
	for i := 1; i < 13; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, [2]int{12/i, i})
			}
		}
	}
	// Print the number of valid arrangements
	fmt.Printf("%d ", len(tot))
	// Print each valid arrangement in sorted order
	for _, a := range tot {
		fmt.Printf("%dx%d ", a[0], a[1])
	}
	fmt.Println()
}

// Entry point of the program
func main() {
	// Read the number of test cases and solve each case
	for i := 0; i < inp(); i++ {
		solve()
	}
}

