package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
func valid(i, j, n, m int) bool {
	return i >= 0 && i < n && j >= 0 && j < m
}

// Function to calculate the sum of an arithmetic series from i to n
func sumn(i, n int) float64 {
	return float64(n-i) * float64(i+n) / 2
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single or multiple integer values from input
func value() []int {
	var vals []int
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break
		}
		vals = append(vals, n)
	}
	return vals
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
func f(s string) string {
	var r strings.Builder
	for _, i := range s {
		if i != '-' && i != ';' && i != '_' {
			r.WriteRune(strings.ToLower(i))
		}
	}
	return r.String()
}

// Main logic of the program
func solve() {
	var l []string
	for i := 0; i < 3; i++ {
		var input string
		fmt.Scan(&input)
		l = append(l, f(input))
	}

	// Generate all permutations
	var permutations []string
	permute(l, 0, len(l)-1, &permutations)

	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var query string
		fmt.Scan(&query)
		if contains(permutations, f(query)) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// Function to generate permutations
func permute(arr []string, left, right int, result *[]string) {
	if left == right {
		*result = append(*result, strings.Join(arr, ""))
	} else {
		for i := left; i <= right; i++ {
			arr[left], arr[i] = arr[i], arr[left] // swap
			permute(arr, left+1, right, result)
			arr[left], arr[i] = arr[i], arr[left] // backtrack
		}
	}
}

// Function to check if a string is in a slice
func contains(slice []string, str string) bool {
	for _, v := range slice {
		if v == str {
			return true
		}
	}
	return false
}

func main() {
	solve()
}

// <END-OF-CODE>
