package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of integers to process
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	
	// Initialize a map to store integers and their counts
	m := make(map[int]int)
	
	// Process each integer input
	for i := 0; i < n; i++ {
		// Read the next integer
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		
		// Check if there is no lower key in the map
		if _, exists := m[num-1]; !exists {
			// If no lower key exists, increment the count for the current number
			m[num]++
		} else {
			// If there is a lower key, get that key and its count
			if m[num-1] == 1 {
				delete(m, num-1)
			} else {
				// Otherwise, decrement the count of the lower key
				m[num-1]--
			}
			
			// Increment the count for the current number
			m[num]++
		}
	}
	
	// Initialize a variable to hold the final answer
	ans := 0
	
	// Sum up all the counts in the map
	for _, val := range m {
		ans += val
	}
	
	// Print the final answer
	fmt.Println(ans)
}

