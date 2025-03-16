// Package name
package main

// Importing necessary libraries
import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value as a tuple
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read multiple values as a tuple
func values() (int, int, int) {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	return a, b, c
}

// Function to read a single value as a list
func inlst() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read multiple values as a list
func inlsts() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read a single value as an integer
func inp() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single value as an integer from stdin
func inps() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single line as a string
func instr() string {
	var a string
	fmt.Scan(&a)
	return a
}

// Function to read a list of strings
func stlst() []string {
	var a []string
	fmt.Scan(&a)
	return a
}

// Helper function to check if a sub-array of given size exists in a list
func help(a, b int, l []int) bool {
	// This function checks if there exists a sub-array of size 'a' in the list 'l' whose sum is equal to 'b'.
	tot := [][]int{}
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}
	for _, i := range tot {
		if sum(i) == b {
			return true
		}
	}
	return false
}

// Main function to solve the problem
func solve() {
	// This function reads a string 'x' and checks if there exists any sub-array of size 1, 2, 3, ..., 12 whose sum is equal to 12.
	// If such a sub-array is found, it is added to the list 'tot'. Finally, the number of such sub-arrays and their sizes are printed.
	x := instr()
	s := []int{}
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}

	fmt.Println(len(tot))
	for _, a := range tot {
		fmt.Printf("%dx%d ", a[0], a[1])
	}
	fmt.Println()
}

// Main function to run the code
func main() {
	for i := 0; i < inp(); i++ {
		solve()
	}
}

