
package main

import (
	"fmt"
	"math"
)

func main() {
	// Creating a new thread and passing it a new instance of MyRunnable class
	go MyRunnable()
}

type MyRunnable struct {
	n, k int
	as   []int
}

func (m *MyRunnable) run() {
	var n, k int
	var as []int

	// Reading input values for n and k
	fmt.Scan(&n, &k)

	// Reading input values for the array as
	as = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i])
	}

	// Printing the result of the calculation
	fmt.Println(Calculator(n, k, as).calculate())
}

type Calculator struct {
	k       int
	answer  int
	isCalc  bool
	lists   [][]int
	visited []bool
}

func Calculator(n, k int, as []int) Calculator {
	c := Calculator{k: k, lists: make([][]int, n), visited: make([]bool, n)}

	// Building the adjacency list representation of the graph
	for i := 0; i < n; i++ {
		c.lists[as[i]-1] = append(c.lists[as[i]-1], i)
	}

	return c
}

func (c *Calculator) calculate() int {
	if !c.isCalc {
		c.dfs(0, -1) // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
		c.isCalc = true
	}
	return c.answer
}

func (c *Calculator) dfs(a, pre int) int {
	h := 0 // Variable to store the height of the current node in the DFS tree

	for _, i := range c.lists[a] { // Iterating through the neighbors of the current node
		h = int(math.Max(float64(h), float64(c.dfs(i, a)))) // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
	}

	if 0 < pre && h == c.k-1 { // Checking if the current node is at the desired height k - 1 from the previous node
		h = 0 // Resetting the height to 0 if it is
		c.answer++ // Incrementing the answer if the current node is at the desired height
	} else {
		h++ // Incrementing the height if the current node is not the base case
	}

	return h // Returning the height of the current node
}

