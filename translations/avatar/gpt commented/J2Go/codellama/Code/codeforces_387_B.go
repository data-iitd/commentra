package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	input := bufio.NewScanner(os.Stdin)

	// Read the number of required items (n) and the number of available items (m)
	n, _ := strconv.Atoi(input.Text())
	m, _ := strconv.Atoi(input.Text())

	// Initialize ArrayLists to store the required items and the available items
	req := make([]int, n)
	pre := make([]int, m)

	// Read the required items from the input and store them in the req list
	for i := 0; i < n; i++ {
		req[i], _ = strconv.Atoi(input.Text())
	}

	// Read the available items from the input and store them in the pre list
	for i := 0; i < m; i++ {
		pre[i], _ = strconv.Atoi(input.Text())
	}

	// Initialize pointers for the required items (i) and available items (j)
	i := n - 1
	j := m - 1

	// Variable to count how many required items can be satisfied
	ans := 0

	// Compare the required items with the available items from the end of both lists
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

