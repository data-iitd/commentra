package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	
	// Step 1: Reading Input
	scanner.Scan()
	n := 0
	fmt.Sscanf(scanner.Text(), "%d", &n) // Read the size of the array
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &a[i]) // Read the elements of the array
	}
	
	// Step 2: Reading a String
	scanner.Scan()
	s := scanner.Text() // Read the string
	
	// Step 3: Initial Sum Calculation
	var sum int64 = 0 // Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'
	
	// Step 4: First Loop
	for i := 0; i < len(s); i++ {
		ch := s[i] // Get the character at position i in the string s
		if ch == 'B' {
			sum += int64(a[i]) // Add the element at position i in array a to sum if the character is 'B'
		}
	}
	
	// Step 5: Main Logic
	ans := sum
	sum1 := sum
	
	// First nested loop to calculate the maximum possible sum by flipping characters in s
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Add the element at position i in array a to sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Subtract the element at position i in array a from sum1 if the character is 'B'
		}
		if sum1 > ans {
			ans = sum1
		}
	}
	
	// Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
	sum1 = sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Add the element at position i in array a to sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Subtract the element at position i in array a from sum1 if the character is 'B'
		}
		if sum1 > ans {
			ans = sum1
		}
	}
	
	// Step 6: Output
	fmt.Println(ans) // Print the maximum sum found
}

