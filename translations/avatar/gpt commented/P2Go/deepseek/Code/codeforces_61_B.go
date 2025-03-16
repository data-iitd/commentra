package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
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
func sumn(i, n int) float64 {
	return float64((n-i)*(i+n)) / 2
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

// Function to read a single line of input and return it as a tuple of integers
func value() []int {
	line := bufio.NewScanner(os.Stdin)
	line.Scan()
	parts := strings.Split(line.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single line of input from stdin and return it as a tuple of integers
func values() []int {
	line := bufio.NewScanner(os.Stdin)
	line.Scan()
	parts := strings.Split(line.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single line of input and return it as a list of integers
func inlst() []int {
	line := bufio.NewScanner(os.Stdin)
	line.Scan()
	parts := strings.Split(line.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single line of input from stdin and return it as a list of integers
func inlsts() []int {
	line := bufio.NewScanner(os.Stdin)
	line.Scan()
	parts := strings.Split(line.Text(), " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

// Function to read a single integer from input
func inp() int {
	reader := bufio.NewReader(os.Stdin)
	num, _ := reader.ReadString('\n')
	num = strings.TrimSpace(num)
	n, _ := strconv.Atoi(num)
	return n
}

// Function to read a single integer from stdin
func inps() int {
	reader := bufio.NewReader(os.Stdin)
	num, _ := reader.ReadString('\n')
	num = strings.TrimSpace(num)
	n, _ := strconv.Atoi(num)
	return n
}

// Function to read a single line of input and return it as a string
func instr() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

// Function to read a single line of input and return it as a list of strings
func stlst() []string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return strings.Split(line, " ")
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
	perms := []string{}
	for _, perm := range itertools.Permutations(l) {
		perms = append(perms, strings.Join(perm, ""))
	}
	
	// Read the number of test cases and check if the processed input is in the list of permutations
	for i := 0; i < inp(); i++ {
		input := f(instr())
		if contains(perms, input) {
			fmt.Println("ACC") // Accepted
		} else {
			fmt.Println("WA") // Wrong Answer
		}
	}
}

// Helper function to check if a slice contains a specific string
func contains(slice []string, item string) bool {
	for _, s := range slice {
		if s == item {
			return true
		}
	}
	return false
}

// Entry point of the program
func main() {
	solve()
}
