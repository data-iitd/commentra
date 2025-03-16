package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of required items (n) and the number of available items (m)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	
	// Initialize slices to store the required items and the available items
	req := make([]int, n)
	pre := make([]int, m)
	
	// Read the required items from the input and store them in the req slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		req[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Read the available items from the input and store them in the pre slice
	for i := 0; i < m; i++ {
		scanner.Scan()
		pre[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Initialize pointers for the required items (i) and available items (j)
	i := n - 1
	j := m - 1
	
	// Variable to count how many required items can be satisfied
	ans := 0
	
	// Compare the required items with the available items from the end of both slices
	for i >= 0 && j >= 0 {
		// If the current required item is greater than the current available item
		if req[i] > pre[j] {
			// Increment the count of satisfied items
			ans++
		} else {
			// Move to the next available item if the current one cannot satisfy the requirement
			j--
		}
		// Move to the next required item
		i--
	}
	
	// Print the total number of satisfied items plus the remaining unsatisfied required items
	fmt.Println(ans + i + 1)
}
