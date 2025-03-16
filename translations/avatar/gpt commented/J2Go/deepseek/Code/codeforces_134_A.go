package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)
	
	// Initialize an array to hold the integers and a variable to store the sum
	arr := make([]int, n)
	sum := 0
	
	// Read the integers into the array and calculate the sum
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
		sum += arr[i] // Accumulate the sum of the elements
	}
	
	// Initialize a counter for valid indices and a StringBuilder for output
	c := 0
	var sb []string
	
	// Check each element to see if it can be the "removed" element
	for i := 0; i < n; i++ {
		// Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
		if (sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i] {
			c++ // Increment the count of valid indices
			sb = append(sb, fmt.Sprintf("%d", i + 1)) // Append the 1-based index to the StringBuilder
		}
	}
	
	// Output the count of valid indices
	fmt.Println(c)
	
	// Output the indices of valid elements
	fmt.Println(fmt.Sprintf("%s", sb))
}
