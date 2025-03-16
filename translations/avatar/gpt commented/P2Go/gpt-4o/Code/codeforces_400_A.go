package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input and convert it to a slice of integers
func readInts() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

// Function to read a single integer from input
func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	val, _ := strconv.Atoi(strings.TrimSpace(line))
	return val
}

// Helper function to determine if a specific arrangement is possible
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

// Main function to solve the problem
func solve() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := reader.ReadString('\n')
	x = strings.TrimSpace(x)
	s := make([]int, len(x))

	for i, char := range x {
		if char == 'O' {
			s[i] = 0
		} else {
			s[i] = 1
		}
	}

	var tot [][2]int

	// Check for all divisors of 12 to find valid arrangements
	for i := 1; i <= 12; i++ {
		if 12%i == 0 { // Check if 'i' is a divisor of 12
			if help(i, 12/i, s) { // Use the helper function to check arrangements
				tot = append(tot, [2]int{12 / i, i}) // Store valid arrangements as tuples
			}
		}
	}

	// Print the number of valid arrangements
	fmt.Print(len(tot), " ")

	// Print each valid arrangement in sorted order
	for _, pair := range tot {
		fmt.Printf("%dx%d ", pair[0], pair[1])
	}
	fmt.Println() // Print a newline at the end
}

// Entry point of the program
func main() {
	testCases := readInt() // Read the number of test cases
	for i := 0; i < testCases; i++ {
		solve()
	}
}

// <END-OF-CODE>
