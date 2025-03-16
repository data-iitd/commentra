
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Start the MyRunnable thread to handle input and output
	go MyRunnable()
}

func MyRunnable() {
	var n int // Number of elements
	var k int // Some parameter k
	var as []int // List to store input values

	// Read input values using Scanner
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text()) // Read the number of elements
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text()) // Read the parameter k
	for i := 0; i < n; i++ {
		scanner.Scan()
		as = append(as, strconv.Atoi(scanner.Text())-1) // Read each element and adjust by subtracting 1
	}

	// Initialize the Calculator object and calculate the result
	fmt.Println(Calculator(n, k, as).Calculate())
}

type Calculator struct {
	k          int // Parameter k
	answer     int // Variable to store the answer
	isCalculate bool // Flag to check if calculation is done
	lists      [][]int // List of lists to store relationships
}

// Constructor to initialize the Calculator object
func Calculator(n int, k int, as []int) Calculator {
	var lists [][]int
	for i := 0; i < n; i++ {
		lists = append(lists, []int{}) // Initialize each list in the lists
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if 0 < i {
			lists[j] = append(lists[j], i) // Add relationship between elements
		} else if 0 < j {
			answer++ // Increment answer if condition is met
		}
	}
	return Calculator{k, answer, false, lists}
}

// Method to calculate the result using DFS
func (c *Calculator) Calculate() int {
	if !c.isCalculate {
		c.dfs(0, 0) // Start DFS from the root node
		c.isCalculate = true // Set the flag to true
	}
	return c.answer // Return the calculated answer
}

// DFS method to traverse through the lists
func (c *Calculator) dfs(a int, pre int) int {
	var h int // Variable to store the height of the tree
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a)) // Recursively calculate the height
	}
	if 0 < pre && h == c.k-1 {
		h = 0 // Reset height if condition is met
		c.answer++ // Increment answer if condition is met
	} else {
		h++ // Increment height otherwise
	}
	return h // Return the height
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// 