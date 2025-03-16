package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 3: Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Step 4: Read the values of n, a, and b
	scanner.Scan()
	values := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(values[0])
	a, _ := strconv.Atoi(values[1])
	b, _ := strconv.Atoi(values[2])
	
	// Step 5: Create two slices to store the lists of integers
	list1 := make([]int, a)
	list2 := make([]int, b)
	
	// Step 6: Read the elements of list1 and list2 from the user
	for i := 0; i < a; i++ {
		scanner.Scan()
		list1[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < b; i++ {
		scanner.Scan()
		list2[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Step 7: Iterate through the range from 1 to n and print the appropriate list number
	for i := 1; i <= n; i++ {
		if contains(list1, i) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

// Helper function to check if a slice contains a specific element
func contains(slice []int, item int) bool {
	for _, value := range slice {
		if value == item {
			return true
		}
	}
	return false
}

