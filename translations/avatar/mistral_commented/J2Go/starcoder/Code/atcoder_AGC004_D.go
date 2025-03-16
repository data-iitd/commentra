
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// <START-OF-CODE>

// MyRunnable is a struct that implements the Runnable interface
type MyRunnable struct {
}

// Run is the method that is called when the thread is started
func (m *MyRunnable) Run() {
	var n int
	var k int
	var as []int
	var sc *bufio.Scanner
	var err error

	// Reading input values for n and k
	if sc, err = bufio.NewScanner(os.Stdin); err!= nil {
		fmt.Println(err)
		return
	}
	if!sc.Scan() {
		fmt.Println("Error reading input")
		return
	}
	if n, err = strconv.Atoi(sc.Text()); err!= nil {
		fmt.Println(err)
		return
	}
	if!sc.Scan() {
		fmt.Println("Error reading input")
		return
	}
	if k, err = strconv.Atoi(sc.Text()); err!= nil {
		fmt.Println(err)
		return
	}

	// Reading input values for the array as
	as = make([]int, n)
	for i := 0; i < n; i++ {
		if!sc.Scan() {
			fmt.Println("Error reading input")
			return
		}
		if as[i], err = strconv.Atoi(sc.Text()); err!= nil {
			fmt.Println(err)
			return
		}
	}

	// Printing the result of the calculation
	fmt.Println(newCalculator(n, k, as).calculate())
}

// Calculator is a struct that implements the Calculator interface
type Calculator struct {
	k         int
	answer    int
	isCalculate bool
	lists     [][]int
}

// NewCalculator is a constructor for the Calculator struct
func newCalculator(n int, k int, as []int) *Calculator {
	c := &Calculator{
		k:         k,
		lists:     make([][]int, n),
	}

	// Building the adjacency list representation of the graph
	for i := 0; i < n; i++ {
		j := as[i]
		if 0 < i {
			c.lists[j] = append(c.lists[j], i) // Adding the index of the current node to the list of neighbors of node j
		} else if 0 < j {
			c.answer++ // Incrementing the answer if the input array contains a negative index
		}
	}

	return c
}

// Calculate is the method that is called to calculate the answer
func (c *Calculator) calculate() int {
	if!c.isCalculate {
		c.dfs(0, -1) // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
		c.isCalculate = true
	}
	return c.answer
}

// dfs is a method that implements the Depth First Search (DFS) algorithm
func (c *Calculator) dfs(a int, pre int) int {
	h := 0 // Variable to store the height of the current node in the DFS tree

	for _, i := range c.lists[a] { // Iterating through the neighbors of the current node
		h = max(h, c.dfs(i, a)) // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
	}

	if 0 < pre && h == c.k - 1 { // Checking if the current node is at the desired height k - 1 from the previous node
		h = 0 // Resetting the height to 0 if it is
		c.answer++ // Incrementing the answer if the current node is at the desired height
	} else {
		h++ // Incrementing the height if the current node is not the base case
	}

	return h // Returning the height of the current node
}

// max is a method that returns the maximum of two integers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// 