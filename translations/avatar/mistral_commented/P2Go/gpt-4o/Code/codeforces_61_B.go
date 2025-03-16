package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strings"
)

// Function to check if given indices are valid
func valid(i, j, n, m int) bool {
	return i >= 0 && i < n && j >= 0 && j < m
}

// Function to calculate sum of first n natural numbers
func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

// Function to calculate square root of a number using quadratic formula
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single line as a slice of integers
func values() []int {
	var input string
	fmt.Scanln(&input)
	strs := strings.Fields(input)
	ints := make([]int, len(strs))
	for i, s := range strs {
		fmt.Sscan(s, &ints[i])
	}
	return ints
}

// Function to read a single integer
func inp() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a single string
func instr() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Function to read a list of integers
func inlst() []int {
	return values()
}

// Function to generate all permutations of a slice of strings
func permutations(a []string) [][]string {
	var helper func([]string, int)
	var result [][]string
	helper = func(arr []string, n int) {
		if n == 1 {
			perm := make([]string, len(arr))
			copy(perm, arr)
			result = append(result, perm)
			return
		}
		for i := 0; i < n; i++ {
			helper(arr, n-1)
			if n%2 == 0 {
				arr[i], arr[n-1] = arr[n-1], arr[i]
			} else {
				arr[0], arr[n-1] = arr[n-1], arr[0]
			}
		}
	}
	helper(a, len(a))
	return result
}

// Main function to solve the problem
func solve() {
	var l []string
	for i := 0; i < 3; i++ {
		l = append(l, instr())
	}
	perms := permutations(l)
	var permStrings []string
	for _, p := range perms {
		permStrings = append(permStrings, strings.Join(p, ""))
	}
	
	var testCases int
	fmt.Scan(&testCases)
	for i := 0; i < testCases; i++ {
		if contains(permStrings, instr()) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// Function to check if a string is in a slice of strings
func contains(slice []string, str string) bool {
	for _, v := range slice {
		if v == str {
			return true
		}
	}
	return false
}

// Starting the program
func main() {
	solve()
}

// <END-OF-CODE>
