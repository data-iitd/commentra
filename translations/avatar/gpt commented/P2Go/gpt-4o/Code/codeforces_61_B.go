package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strings"
)

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
func valid(i, j, n, m int) bool {
	return i >= 0 && i < n && j >= 0 && j < m
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
func sumn(i, n int) float64 {
	return float64(n-i) * float64(i+n) / 2
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single line of input and return it as a slice of integers
func values() []int {
	var input string
	fmt.Scanln(&input)
	strs := strings.Fields(input)
	ints := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscanf(s, "%d", &ints[i])
	}
	return ints
}

// Function to read a single integer from input
func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to process a string by removing specific characters and converting it to lowercase
func f(s string) string {
	var r strings.Builder
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r.WriteRune(unicode.ToLower(i))
		}
	}
	return r.String()
}

// Main function to solve the problem
func solve() {
	l := make([]string, 0, 3)
	// Read three lines of input, process them, and store the results in a slice
	for i := 0; i < 3; i++ {
		var input string
		fmt.Scanln(&input)
		l = append(l, f(input))
	}

	// Generate all permutations of the processed strings
	permutations := make(map[string]struct{})
	var permute func([]string, int)
	permute = func(arr []string, n int) {
		if n == 1 {
			permutations[strings.Join(arr, "")] = struct{}{}
			return
		}
		for i := 0; i < n; i++ {
			permute(arr, n-1)
			if n%2 == 1 {
				arr[0], arr[n-1] = arr[n-1], arr[0]
			} else {
				arr[i], arr[n-1] = arr[n-1], arr[i]
			}
		}
	}
	permute(l, len(l))

	// Read the number of test cases and check if the processed input is in the list of permutations
	for i := 0; i < inp(); i++ {
		var input string
		fmt.Scanln(&input)
		if _, exists := permutations[f(input)]; exists {
			fmt.Println("ACC") // Accepted
		} else {
			fmt.Println("WA")  // Wrong Answer
		}
	}
}

// Entry point of the program
func main() {
	solve()
}

// <END-OF-CODE>
