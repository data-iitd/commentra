package main

import (
	"fmt"
	"os"
)

type Calculator struct {
	k          int
	answer     int
	isCalculate bool
	lists      [][]int
}

func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{k: k, lists: make([][]int, n)}
	for i := 0; i < n; i++ {
		c.lists[i] = []int{}
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			c.lists[j]. = append(c.lists[j], i) // Add relationship between elements
		} else if j > 0 {
			c.answer++ // Increment answer if condition is met
		}
	}
	return c
}

func (c *Calculator) Calculate() int {
	if !c.isCalculate {
		c.dfs(0, 0) // Start DFS from the root node
		c.isCalculate = true // Set the flag to true
	}
	return c.answer // Return the calculated answer
}

func (c *Calculator) dfs(a, pre int) int {
	h := 0 // Variable to store the height of the tree
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a)) // Recursively calculate the height
	}
	if pre > 0 && h == c.k-1 {
		h = 0 // Reset height if condition is met
		c.answer++ // Increment answer if condition is met
	} else {
		h++ // Increment height otherwise
	}
	return h // Return the height
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the number of elements and parameter k
	as := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i]) // Read each element
		as[i]-- // Adjust by subtracting 1
	}

	calculator := NewCalculator(n, k, as) // Initialize the Calculator object
	fmt.Println(calculator.Calculate()) // Calculate and print the result
}

// <END-OF-CODE>
