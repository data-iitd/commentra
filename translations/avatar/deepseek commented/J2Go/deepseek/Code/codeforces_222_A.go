package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements (n) and a threshold value (k)
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d %d", &n, &k)
	
	// Initialize variables to keep track of the last number and its consecutive occurrences
	l, c := 0, 1
	
	// Loop to read n numbers and count consecutive occurrences
	for i := 0; i < n; i++ {
		scanner.Scan()
		a, _ := fmt.Sscanf(scanner.Text(), "%d", &a)
		if a == l {
			c += 1 // Increment count if the current number is the same as the last
		} else {
			c = 1 // Reset count if the current number is different
		}
		l = a // Update the last number
	}
	
	// Check if the number of consecutive occurrences plus the threshold value is greater than n
	if c + k > n {
		fmt.Println(n - c) // Print the number of elements to remove
	} else {
		fmt.Println(-1) // Print -1 if it's not possible to satisfy the condition
	}
}

