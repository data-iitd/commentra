package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line of input and convert it to a tuple of integers
func value() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		ints[i] = num
	}
	return ints, nil
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
func values() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		ints[i] = num
	}
	return ints, nil
}

// Function to read a single line of input and return a list of integers
func inlst() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		ints[i] = num
	}
	return ints, nil
}

// Function to read a single line of input from stdin and return a list of integers
func inlsts() ([]int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	parts := strings.Fields(input)
	ints := make([]int, len(parts))
	for i, part := range parts {
		num, err := strconv.Atoi(part)
		if err != nil {
			return nil, err
		}
		ints[i] = num
	}
	return ints, nil
}

// Function to read a single integer from input
func inp() (int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	num, err := strconv.Atoi(strings.TrimSpace(input))
	if err != nil {
		return 0, err
	}
	return num, nil
}

// Function to read a single integer from stdin
func inps() (int, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return 0, err
	}
	num, err := strconv.Atoi(strings.TrimSpace(input))
	if err != nil {
		return 0, err
	}
	return num, nil
}

// Function to read a single line of input and return it as a string
func instr() (string, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return "", err
	}
	return strings.TrimSpace(input), nil
}

// Function to read a single line of input and return it as a list of strings
func stlst() ([]string, error) {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		return nil, err
	}
	return strings.Fields(input), nil
}

// Helper function to determine if a specific arrangement is possible
func help(a int, b int, l []int) bool {
	tot := [][]int{}
	// Create sublists of length 'a' from the list 'l'
	for i := 0; i < b; i++ {
		sublist := l[i*a : i*a+a]
		tot = append(tot, sublist)
	}

	// Check if any combination of the sublists sums to 'b'
	for _, combo := range tot {
		sum := 0
		for _, num := range combo {
			sum += num
		}
		if sum == b {
			return true
		}
	}
	return false
}

// Main function to solve the problem
func solve() {
	tot := []string{}

	// Read the input string
	input, err := instr()
	if err != nil {
		fmt.Println(err)
		return
	}
	s := []int{}

	// Convert the input string into a list of integers (0 for 'O', 1 for 'X')
	for _, char := range input {
		if char == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	// Check for all divisors of 12 to find valid arrangements
	for i := 1; i <= 12; i++ {
		if 12%i == 0 { // Check if 'i' is a divisor of 12
			if help(i, 12/i, s) { // Use the helper function to check arrangements
				tot = append(tot, fmt.Sprintf("%dx%d", 12/i, i)) // Store valid arrangements as strings
			}
		}
	}

	// Print the number of valid arrangements
	fmt.Printf("%d ", len(tot))

	// Print each valid arrangement in sorted order
	for _, arrangement := range tot {
		fmt.Printf("%s ", arrangement)
	}
	fmt.Println() // Print a newline at the end
}

// Entry point of the program
func main() {
	// Read the number of test cases and solve each case
	numTests, err := inp()
	if err != nil {
		fmt.Println(err)
		return
	}
	for i := 0; i < numTests; i++ {
		solve()
	}
}
