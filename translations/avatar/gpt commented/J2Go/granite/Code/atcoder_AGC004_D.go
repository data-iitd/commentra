
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Calculator struct {
	k        int
	answer   int
	isCalculate bool
	lists    [][]int
}

func main() {
	// Start a new goroutine to run the MyRunnable struct
	go MyRunnable{}
}

type MyRunnable struct{}

func (mr *MyRunnable) run() {
	var n, k int
	var as []int
	// Use a Scanner to read input values from the console
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text()) // Read the number of elements
	sc.Scan()
	k, _ = strconv.Atoi(sc.Text()) // Read the threshold value
	// Read n integers and adjust them (subtract 1) before adding to the list
	for i := 0; i < n; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		as = append(as, a-1)
	}
	// Create a Calculator instance and calculate the result, then print it
	fmt.Println(Calculator{n, k, false, make([][]int, n)}.calculate(as))
}

func (c *Calculator) calculate(as []int) int {
	// If calculation hasn't been performed yet, start the DFS
	if!c.isCalculate {
		c.dfs(0, 0, as) // Start DFS from node 0
		c.isCalculate = true // Mark calculation as done
	}
	return c.answer // Return the final answer
}

func (c *Calculator) dfs(a, pre int, as []int) int {
	h := 0 // Height of the current node
	// Explore all adjacent nodes
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a, as)) // Recursively find the height
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// End of code
