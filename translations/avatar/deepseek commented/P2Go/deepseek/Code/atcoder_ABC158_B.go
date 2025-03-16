package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read an integer
func I() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	return parseInt(input)
}

// Function to read a map of integers
func MI() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Split(input, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		result[i] = parseInt(part)
	}
	return result
}

// Function to read a list of integers
func LI() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Split(input, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		result[i] = parseInt(part)
	}
	return result
}

// Helper function to parse string to int
func parseInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}

// Main function
func main() {
	const mod = 1000000007 // Modulo value
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	N := parseInt(parts[0])
	A := parseInt(parts[1])
	B := parseInt(parts[2])
	ans := 0 // Initializing the result variable
	
	// Calculating the number of complete cycles of A + B within N
	rep := N / (A + B)
	
	// Updating the result with the number of complete cycles multiplied by A
	ans += rep * A
	
	// Calculating the remaining days after the complete cycles
	res := N - rep * (A + B)
	
	// Updating the result with the minimum of the remaining days and A
	ans += min(res, A)
	
	// Printing the final result
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
