package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize an array to hold the integer values
	a := make([]int, n)
	
	// Populate the array with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}
	
	// Read the string input which consists of characters 'A' and 'B'
	scanner.Scan()
	s := scanner.Text()
	
	// Initialize a variable to hold the sum of values corresponding to 'B'
	var sum int64 = 0
	
	// Calculate the initial sum based on the positions of 'B' in the string
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += int64(a[i]) // Add the value to sum if the character is 'B'
		}
	}
	
	// Store the initial sum as the maximum answer found so far
	ans := sum
	var sum1 int64 = sum
	
	// Iterate through the string to calculate the maximum possible sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Increase sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Decrease sum1 if the character is not 'A'
		}
		
		// Update the maximum answer if the current sum1 is greater
		if sum1 > ans {
			ans = sum1
		}
	}
	
	// Reset sum1 to the initial sum for the next calculation
	sum1 = sum
	
	// Iterate through the string in reverse to calculate the maximum possible sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += int64(a[i]) // Increase sum1 if the character is 'A'
		} else {
			sum1 -= int64(a[i]) // Decrease sum1 if the character is not 'A'
		}
		
		// Update the maximum answer if the current sum1 is greater
		if sum1 > ans {
			ans = sum1
		}
	}
	
	// Output the maximum sum found
	fmt.Println(ans)
}
