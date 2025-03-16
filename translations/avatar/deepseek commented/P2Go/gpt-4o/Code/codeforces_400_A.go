package main

import (
	"fmt"
	"os"
	"strings"
)

// Function to read a single value from input
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read multiple values from input
func values() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read a list of integers from input
func inlst() []int {
	var input string
	fmt.Scan(&input)
	strs := strings.Fields(input)
	lst := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscan(s, &lst[i])
	}
	return lst
}

// Function to read a list of integers from stdin
func inlsts() []int {
	var input string
	fmt.Scan(&input)
	strs := strings.Fields(input)
	lst := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscan(s, &lst[i])
	}
	return lst
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

// Function to read a single string from input
func instr() string {
	var input string
	fmt.Scan(&input)
	return input
}

// Function to read a list of strings from input
func stlst() []string {
	var input string
	fmt.Scan(&input)
	return strings.Fields(input)
}

// Helper function to check if a grid of given dimensions can be formed
func help(a, b int, l []int) bool {
	tot := make([][]int, b)
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}
	for i := 0; i < a; i++ {
		sum := 0
		for j := 0; j < b; j++ {
			sum += tot[j][i]
		}
		if sum == b {
			return true
		}
	}
	return false
}

// Main solving function
func solve() {
	var tot [][]int
	x := instr()
	s := make([]int, len(x))
	for i, char := range x {
		if char == 'O' {
			s[i] = 0
		} else {
			s[i] = 1
		}
	}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}
	fmt.Print(len(tot), " ")
	for _, pair := range tot {
		fmt.Printf("%dx%d ", pair[0], pair[1])
	}
	fmt.Println()
}

// Main execution block
func main() {
	for i := inp(); i > 0; i-- {
		solve()
	}
}

// <END-OF-CODE>
