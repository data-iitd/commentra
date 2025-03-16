package main

import (
	"fmt"
	"os"
)

type Calculator struct {
	k           int
	answer      int
	isCalculate bool
	lists       [][]int
}

func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{k: k, lists: make([][]int, n)}
	for i := 0; i < n; i++ {
		c.lists[i] = []int{}
	}
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

func (c *Calculator) Calculate() int {
	if !c.isCalculate {
		c.dfs(0, 0)
		c.isCalculate = true
	}
	return c.answer
}

func (c *Calculator) dfs(a, pre int) int {
	h := 0
	for _, i := range c.lists[a] {
		h = max(h, c.dfs(i, a))
	}
	if pre > 0 && h == c.k-1 {
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

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	as := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&as[i])
		as[i]-- // Adjust the input value
	}
	calculator := NewCalculator(n, k, as)
	fmt.Println(calculator.Calculate())
}

// <END-OF-CODE>
