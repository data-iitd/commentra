package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Read the first line of input and split it into an array of strings
	sa, _ := reader.ReadString('\n')
	sa = sa[:len(sa)-1] // Remove the newline character
	saSlice := strings.Split(sa, " ")
	
	// Parse the first element as an integer 'n'
	n := parseInt(saSlice[0])
	
	// Read the second line of input and split it into an array of strings
	sa, _ = reader.ReadString('\n')
	sa = sa[:len(sa)-1] // Remove the newline character
	saSlice = strings.Split(sa, " ")
	
	// Initialize an integer array 'c' of size 'n'
	c := make([]int, n)
	
	// Populate the array 'c' with integers from the input
	for i := 0; i < n; i++ {
		c[i] = parseInt(saSlice[i])
	}
	
	// Close the BufferedReader
	// Note: In Go, we don't need to explicitly close a reader
	
	// Define a modulus value for calculations
	mod := 1000000007
	
	// If there is only one element, calculate and print the result directly
	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}
	
	// Sort the array 'c' in parallel
	sort.Ints(c)
	
	// Calculate powers of 2 for later use
	b := power(2, n)
	a := power(2, n - 2)
	
	// Initialize the answer variable
	ans := 0
	
	// Calculate the final answer using a loop
	for i := 2; i <= n + 1; i++ {
		// Calculate the value for the current iteration
		val := a * int(i) % mod
		val *= c[n + 1 - i]
		val %= mod
		
		// Accumulate the result
		ans += val
		ans %= mod
	}
	
	// Multiply the accumulated answer by 'b' and take modulus
	ans *= b
	ans %= mod
	
	// Print the final result
	fmt.Println(ans)
}

// Method to calculate (x^n) % mod using recursion
func power(x, n int) int {
	// Define a modulus value for calculations
	mod := 1000000007
	
	// Base case: x^0 = 1
	if n == 0 {
		return 1
	}
	
	// Recursively calculate power
	val := power(x, n / 2)
	
	// Square the result and take modulus
	val = val * val % mod
	
	// If n is odd, multiply by x and take modulus
	if n % 2 == 1 {
		val = val * x % mod
	}
	
	// Return the final result
	return val
}

// Helper function to parse string to int
func parseInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}

