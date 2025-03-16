package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Start a new thread to run the MyRunnable class
	go MyRunnable()
}

func MyRunnable() {
	var n int // Number of elements
	var k int // A specific threshold value
	var as []int // List to store input values

	// Use a Scanner to read input values from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text()) // Read the number of elements
	sc.Scan()
	k, _ = strconv.Atoi(sc.Text()) // Read the threshold value
	// Read n integers and adjust them (subtract 1) before adding to the list
	for i := 0; i < n; i++ {
		sc.Scan()
		as = append(as, strconv.Atoi(sc.Text())-1)
	}

	// Create a Calculator instance and calculate the result, then print it
	fmt.Println(Calculator(n, k, as).calculate())
}

func Calculator(n int, k int, as []int) Calculator {
	var answer int = 0 // Store the final answer
	var isCalculate bool = false // Flag to check if calculation is done
	var lists [][]int = make([][]int, n) // Adjacency list representation

	// Initialize the adjacency list
	for i := 0; i < n; i++ {
		lists[i] = make([]int, 0)
	}
	// Build the adjacency list based on the input values
	for i := 0; i < n; i++ {
		j := as[i] // Get the corresponding value
		if 0 < i {
			lists[j] = append(lists[j], i) // Add edge to the adjacency list
		} else if 0 < j {
			answer++ // Increment answer if the condition is met
		}
	}

	return Calculator{k, answer, isCalculate, lists}
}

func (c *Calculator) calculate() int {
	// If calculation hasn't been performed yet, start the DFS
	if !c.isCalculate {
		c.dfs(0, 0) // Start DFS from node 0
		c.isCalculate = true // Mark calculation as done
	}
	return c.answer // Return the final answer
}

func (c *Calculator) dfs(a int, pre int) int {
	var h int = 0 // Height of the current node
	// Explore all adjacent nodes
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a)) // Recursively find the height
	}
	// Check if the conditions for incrementing the answer are met
	if 0 < pre && h == c.k-1 {
		h = 0 // Reset height if condition is met
		c.answer++ // Increment answer
	} else {
		h++ // Increment height
	}
	return h // Return the height
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

