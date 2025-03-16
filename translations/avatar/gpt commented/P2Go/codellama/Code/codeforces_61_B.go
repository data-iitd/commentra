
package main

import (
	"fmt"
	"strings"
)

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
func sqfun(a, b, c int) int {
	return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / (2 * a)
}

// Function to read a single line of input and return it as a tuple of integers
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read a single line of input from stdin and return it as a tuple of integers
func values() (int, int) {
	var a, b int
	fmt.Fscan(os.Stdin, &a, &b)
	return a, b
}

// Function to read a single line of input and return it as a list of integers
func inlst() []int {
	var a []int
	fmt.Scan(&a)
	return a
}

// Function to read a single line of input from stdin and return it as a list of integers
func inlsts() []int {
	var a []int
	fmt.Fscan(os.Stdin, &a)
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
	fmt.Fscan(os.Stdin, &a)
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

// Function to process a string by removing specific characters and converting it to lowercase
func f(s string) string {
	r := ""
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r += strings.ToLower(string(i))
		}
	}
	return r
}

// Main function to solve the problem
func solve() {
	l := []string{}
	// Read three lines of input, process them, and store the results in a list
	for i := 0; i < 3; i++ {
		l = append(l, f(instr()))
	}

	// Generate all permutations of the processed strings
	t := [][]string{}
	for _, i := range l {
		t = append(t, strings.Split(i, ""))
	}
	l = []string{}
	// Create a list of concatenated permutations
	for _, i := range t {
		l = append(l, strings.Join(i, ""))
	}

	// Read the number of test cases and check if the processed input is in the list of permutations
	for i := 0; i < inp(); i++ {
		if f(instr()) == l[i] {
			fmt.Println("ACC") // Accepted
		} else {
			fmt.Println("WA") // Wrong Answer
		}
	}
}

// Entry point of the program
func main() {
	solve()
}

