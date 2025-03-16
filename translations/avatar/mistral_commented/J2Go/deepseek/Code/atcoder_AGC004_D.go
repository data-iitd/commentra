package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new thread and passing it a new instance of MyRunnable class
	go func() {
		var n, k int
		var as []int

		scanner := bufio.NewScanner(os.Stdin)
		scanner.Split(bufio.ScanWords)

		// Reading input values for n and k
		scanner.Scan()
		n, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ = strconv.Atoi(scanner.Text())

		// Reading input values for the array as
		as = make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			as[i], _ = strconv.Atoi(scanner.Text())
			as[i]--
		}

		// Printing the result of the calculation
		fmt.Println(newCalculator(n, k, as).calculate())
	}()
}

type Calculator struct {
	k      int
	answer int
	isCalc bool
	lists  [][]int
}

func newCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{
		k:     k,
		lists: make([][]int, n),
	}

	// Building the adjacency list representation of the graph
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			c.lists[j] = append(c.lists[j], i)
		} else if j > 0 {
			c.answer++
		}
	}

	return c
}

func (c *Calculator) calculate() int {
	if !c.isCalc {
		c.dfs(0, -1)
		c.isCalc = true
	}
	return c.answer
}

func (c *Calculator) dfs(a, pre int) int {
	h := 0

	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a))
	}

	if pre != -1 && h == c.k-1 {
		h = 0
		c.answer++
	} else {
		h++
	}

	return h
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
