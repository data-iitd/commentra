

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new thread and passing it a new instance of MyRunnable struct
	go MyRunnable{}
}

type MyRunnable struct{}

func (mr *MyRunnable) Run() {
	var n, k int
	var as []int

	// Reading input values for n and k
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

	// Reading input values for the array as
	as = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &as[i])
		as[i]--
	}

	// Printing the result of the calculation
	fmt.Println(NewCalculator(n, k, as).Calculate())
}

type Calculator struct {
	k        int
	answer   int
	isCalculate bool
	lists    [][]int
}

func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{
		k: k,
	}

	// Initializing the 2D list with slices of size n
	c.lists = make([][]int, n)
	for i := 0; i < n; i++ {
		c.lists[i] = make([]int, 0)
	}

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

func (c *Calculator) Calculate() int {
	if!c.isCalculate {
		c.dfs(0, -1) // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
		c.isCalculate = true
	}
	return c.answer
}

func (c *Calculator) dfs(a, pre int) int {
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

These comments should provide a clear understanding of the code logic for each block. Let me know if you need any further clarification.