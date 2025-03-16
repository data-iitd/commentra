package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Declare variables for the number of elements and sizes of the two lists
	var n, a, b int
	
	// Read the values for n, a, and b from the input
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Fields(line)
	n, _ = strconv.Atoi(parts[0])
	a, _ = strconv.Atoi(parts[1])
	b, _ = strconv.Atoi(parts[2])
	
	// Initialize two slices to store the elements of the two lists
	list1 := make([]int, a)
	list2 := make([]int, b)
	
	// Read 'a' integers into list1
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Fields(line)
	for i := 0; i < a; i++ {
		list1[i], _ = strconv.Atoi(parts[i])
	}
	
	// Read 'b' integers into list2
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Fields(line)
	for i := 0; i < b; i++ {
		list2[i], _ = strconv.Atoi(parts[i])
	}
	
	// Iterate from 0 to n-1 to check the presence of each index in list1
	for i := 0; i < n; i++ {
		// If the current index + 1 is in list1, print 1
		if contains(list1, i + 1) {
			fmt.Print(1, " ")
		} else {
			// Otherwise, print 2
			fmt.Print(2, " ")
		}
	}
}

// Helper function to check if a slice contains a specific element
func contains(slice []int, element int) bool {
	for _, value := range slice {
		if value == element {
			return true
		}
	}
	return false
}

