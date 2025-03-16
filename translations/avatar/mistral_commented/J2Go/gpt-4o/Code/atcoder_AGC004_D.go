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

// Constructor for Calculator
func NewCalculator(n int, k int, as []int) *Calculator {
	c := &Calculator{k: k, lists: make([][]int, n)}
	
	// Building the adjacency list representation of the graph
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			c.lists[j] = append(c.lists[j], i) // Adding the index of the current node to the list of neighbors of node j
		} else if j > 0 {
			c.answer++ // Incrementing the answer if the input array contains a negative index
		}
	}
	return c
}

// Method to calculate the answer
func (c *Calculator) Calculate() int {
	if !c.isCalculate {
		c.dfs(0, -1) // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
		c.isCalculate = true
	}
	return c.answer
}

// DFS method to traverse the graph
func (c *Calculator) dfs(a int, pre int) int {
	h := 0 // Variable to store the height of the current node in the DFS tree

	for _, i := range c.lists[a] { // Iterating through the neighbors of the current node
		h = max(h, c.dfs(i, a)) // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
	}

	if pre > 0 && h == c.k-1 { // Checking if the current node is at the desired height k - 1 from the previous node
		h = 0 // Resetting the height to 0 if it is
		c.answer++ // Incrementing the answer if the current node is at the desired height
	} else {
		h++ // Incrementing the height if the current node is not the base case
	}

	return h // Returning the height of the current node
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Reading input values for n and k

	as := make([]int, n) // Slice to store the input array
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i]) // Reading input values for the array as
		as[i]-- // Adjusting the index to be zero-based
	}

	// Creating a new Calculator instance and printing the result of the calculation
	calculator := NewCalculator(n, k, as)
	fmt.Println(calculator.Calculate())
}

// <END-OF-CODE>
