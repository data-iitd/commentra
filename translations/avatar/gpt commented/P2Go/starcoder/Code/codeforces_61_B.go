
package main

import (
	"bufio"
	"fmt"
	"os"
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
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single line of input and return it as a tuple of integers
func value() (int, int, int, int) {
	var i, j, n, m int
	fmt.Scanf("%d %d %d %d", &i, &j, &n, &m)
	return i, j, n, m
}

// Function to read a single line of input from stdin and return it as a tuple of integers
func values() (int, int, int, int) {
	var i, j, n, m int
	fmt.Fscanf(os.Stdin, "%d %d %d %d", &i, &j, &n, &m)
	return i, j, n, m
}

// Function to read a single line of input and return it as a list of integers
func inlst() []int {
	var i, j, n, m int
	fmt.Scanf("%d %d %d %d", &i, &j, &n, &m)
	return []int{i, j, n, m}
}

// Function to read a single line of input from stdin and return it as a list of integers
func inlsts() []int {
	var i, j, n, m int
	fmt.Fscanf(os.Stdin, "%d %d %d %d", &i, &j, &n, &m)
	return []int{i, j, n, m}
}

// Function to read a single integer from input
func inp() int {
	var i int
	fmt.Scanf("%d", &i)
	return i
}

// Function to read a single integer from stdin
func inps() int {
	var i int
	fmt.Fscanf(os.Stdin, "%d", &i)
	return i
}

// Function to read a single line of input and return it as a string
func instr() string {
	var s string
	fmt.Scanf("%s", &s)
	return s
}

// Function to read a single line of input and return it as a list of strings
func stlst() []string {
	var s string
	fmt.Scanf("%s", &s)
	return strings.Split(s, " ")
}

// Function to process a string by removing specific characters and converting it to lowercase
func f(s string) string {
	r := ""
	for i := 0; i < len(s); i++ {
		if s[i]!= '-' && s[i]!= ';' && s[i]!= '_' {
			r += strings.ToLower(string(s[i]))
		}
	}
	return r
}

// Main function to solve the problem
func main() {
	l := make([]string, 3)
	// Read three lines of input, process them, and store the results in a list
	for i := 0; i < 3; i++ {
		l[i] = f(instr())
	}
	// Generate all permutations of the processed strings
	t := permutations(l, len(l))
	l = make([]string, 0)
	// Create a list of concatenated permutations
	for i := 0; i < len(t); i++ {
		l = append(l, strings.Join(t[i], ""))
	}
	// Read the number of test cases and check if the processed input is in the list of permutations
	for i := 0; i < inp(); i++ {
		if f(instr()) == l[i] {
			fmt.Println("ACC") // Accepted
		} else {
			fmt.Println("WA")  // Wrong Answer
	}
}

// Function to generate all permutations of a list
func permutations(l []string, n int) [][]string {
	var r [][]string
	if n == 1 {
		r = append(r, l)
	} else {
		for i := 0; i < n; i++ {
			t := l[i]
			l = append(l[:i], l[i+1:]...)
			p := permutations(l, n-1)
			for j := 0; j < len(p); j++ {
				r = append(r, append([]string{t}, p[j]...))
			}
			l = append(l[:i], append([]string{t}, l[i:]...)...)
		}
	}
	return r
}

