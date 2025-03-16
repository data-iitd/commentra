package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Start a new goroutine to run the MyRunnable function
	go func() {
		var n, k int
		var as []int

		// Use a Scanner to read input values from the console
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		n, _ = strconv.Atoi(scanner.Text()) // Read the number of elements
		scanner.Scan()
		k, _ = strconv.Atoi(scanner.Text()) // Read the threshold value

		// Read n integers and adjust them (subtract 1) before adding to the list
		scanner.Scan()
		elements := scanner.Text()
		elementsSlice := strings.Split(elements, " ")
		for _, element := range elementsSlice {
			num, _ := strconv.Atoi(element)
			as = append(as, num-1)
		}

		// Create a Calculator instance and calculate the result, then print it
		fmt.Println(Calculator(n, k, as).calculate())
	}()
}

// Calculator struct to hold the necessary data
type Calculator struct {
	k       int
	answer  int
	isCalc  bool
	adjList [][]int
}

// Constructor for the Calculator
func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{
		k:       k,
		answer:  0,
		isCalc:  false,
		adjList: make([][]int, n),
	}

	// Build the adjacency list based on the input values
	for i := 0; i < n; i++ {
		c.adjList[i] = []int{}
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			c.adjList[j] = append(c.adjList[j], i)
		} else if j > 0 {
			c.answer++
		}
	}
	return c
}

// Method to calculate the answer
func (c *Calculator) calculate() int {
	// If calculation hasn't been performed yet, start the DFS
	if !c.isCalc {
		c.dfs(0, 0)
		c.isCalc = true
	}
	return c.answer
}

// Depth-First Search (DFS) method to explore the graph
func (c *Calculator) dfs(a, pre int) int {
	h := 0 // Height of the current node
	// Explore all adjacent nodes
	for _, i := range c.adjList[a] {
		h = max(h, c.dfs(i, a)) // Recursively find the height
	}
	// Check if the conditions for incrementing the answer are met
	if pre > 0 && h == c.k-1 {
		h = 0 // Reset height if condition is met
		c.answer++ // Increment answer
	} else {
		h++ // Increment height
	}
	return h
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

