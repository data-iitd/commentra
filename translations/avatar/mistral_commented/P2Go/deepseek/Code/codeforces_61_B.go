package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Function to check if given indices are valid
func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

// Function to calculate sum of first n natural numbers
func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

// Function to calculate square root of a number using quadratic formula
func sqfun(a, b, c int) int {
	return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 * a
}

// Function to read a single line as a tuple of integers
func value() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Function to read a single line as a list of integers
func values() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Function to read a single integer
func inp() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Function to read a single integer from the standard input as a string
func instr() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to read a list of integers
func inlst() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Function to read a list of integers from the standard input
func inlsts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Function to read a single integer from the standard input
func inp() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Function to read a single integer from the standard input
func inps() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Function to read a single string from the standard input
func instr() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to convert a string to a list
func stlst() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	return parts
}

// Main function to solve the problem
func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	l := []string{scanner.Text(), scanner.Text(), scanner.Text()}
	perms := permute(l)
	for i := 0; i < inp(); i++ {
		word := instr()
		if contains(perms, word) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// Helper function to generate permutations
func permute(arr []string) []string {
	var helper func([]string, int)
	res := []string{}

	helper = func(arr []string, n int) {
		if n == 1 {
			res = append(res, strings.Join(arr, ""))
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}

	helper(arr, len(arr))
	return res
}

// Helper function to check if a string is in the list of permutations
func contains(perms []string, word string) bool {
	for _, perm := range perms {
		if perm == word {
			return true
		}
	}
	return false
}

// Starting the program
func main() {
	solve()
}

