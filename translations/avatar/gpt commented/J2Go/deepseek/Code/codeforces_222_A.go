package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements (n) and the threshold (k)
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d %d", &n, &k)
	if n != 2 {
		fmt.Println("Invalid input: expected 2 integers")
		return
	}
	
	// Initialize variables to count consecutive occurrences
	l, c := 0, 1
	
	// Loop through each element to count consecutive occurrences
	for i := 0; i < n; i++ {
		// Read the next integer from input
		scanner.Scan()
		a, _ := fmt.Sscanf(scanner.Text(), "%d", &a)
		if a == 0 {
			fmt.Println("Invalid input: expected an integer")
			return
		}
		
		// Check if the current number is the same as the last one
		if a == l {
			c += 1 // Increment the count of consecutive occurrences
		} else {
			c = 1 // Reset the count if the number changes
		}
		
		// Update the last number to the current one
		l = a
	}
	
	// Check if the count of consecutive numbers plus k exceeds n
	if c + k > n {
		// If true, print the number of elements that are not part of the consecutive sequence
		fmt.Println(n - c)
	} else {
		// Otherwise, print -1 indicating the condition is not met
		fmt.Println(-1)
	}
}
