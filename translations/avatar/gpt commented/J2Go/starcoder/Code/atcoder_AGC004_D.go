package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// MyRunnable is a class that implements the Runnable interface
type MyRunnable struct {
}

// Run is the method that will be called by the Go runtime
func (r MyRunnable) Run() {
	var n, k int
	var as []int
	var sc *bufio.Scanner
	var err error

	// Use a Scanner to read input values from the console
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	if sc.Scan() {
		n, err = strconv.Atoi(sc.Text())
		if err!= nil {
			fmt.Println(err)
			return
		}
	}
	if sc.Scan() {
		k, err = strconv.Atoi(sc.Text())
		if err!= nil {
			fmt.Println(err)
			return
		}
	}
	for i := 0; i < n; i++ {
		if sc.Scan() {
			as = append(as, int(sc.Text())-1)
		}
	}

	// Create a Calculator instance and calculate the result, then print it
	fmt.Println(newCalculator(n, k, as).calculate())
}

// Calculator is a class that implements the Calculator interface
type Calculator struct {
	k        int
	answer   int
	isCalculate bool
	lists    [][]int
}

// NewCalculator is a constructor to initialize the Calculator with input values
func newCalculator(n int, k int, as []int) *Calculator {
	c := new(Calculator)
	c.k = k
	c.lists = make([][]int, n)
	for i := 0; i < n; i++ {
		c.lists[i] = make([]int, 0)
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if 0 < i {
			c.lists[j] = append(c.lists[j], i)
		} else if 0 < j {
			c.answer++
		}
	}
	return c
}

// Calculate is a method to calculate the answer
func (c *Calculator) calculate() int {
	// If calculation hasn't been performed yet, start the DFS
	if!c.isCalculate {
		c.dfs(0, 0)
		c.isCalculate = true
	}
	return c.answer
}

// DFS is a method to explore the graph
func (c *Calculator) dfs(a int, pre int) int {
	h := 0
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a))
	}
	if 0 < pre && h == c.k-1 {
		h = 0
		c.answer++
	} else {
		h++
	}
	return h
}

// max returns the larger of its 2 arguments
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE

// main is the entry point of the program
func main() {
	// Start a new thread to run the MyRunnable class
	go new(MyRunnable).Run()
}

Translate the above Go code to Python and end with comment "