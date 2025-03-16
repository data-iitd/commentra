package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of required items (n) and the number of available items (m)
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of required items (n): ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Print("Enter the number of available items (m): ")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize slices to store the required items and the available items
	req := make([]int, n)
	pre := make([]int, m)

	// Read the required items from the input and store them in the req slice
	for i := 0; i < n; i++ {
		fmt.Print("Enter the required item: ")
		req[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}

	// Read the available items from the input and store them in the pre slice
	for i := 0; i < m; i++ {
		fmt.Print("Enter the available item: ")
		pre[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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

