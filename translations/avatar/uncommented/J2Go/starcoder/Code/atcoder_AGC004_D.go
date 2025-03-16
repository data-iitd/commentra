package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Calculator struct {
	k        int
	answer   int
	isCalculate bool
	lists    [][]int
}

func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{k: k}
	c.lists = make([][]int, n)
	for i := 0; i < n; i++ {
		c.lists[i] = make([]int, 0)
	}
	for i := 0; i < n; i++ {
		j := as[i]
		if i > 0 {
			c.lists[j-1] = append(c.lists[j-1], i)
		} else if j > 0 {
			c.answer++
		}
	}
	return c
}

func (c *Calculator) Calculate() int {
	if!c.isCalculate {
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
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ := strconv.Atoi(sc.Text())
	as := make([]int, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		as[i], _ = strconv.Atoi(sc.Text())
	}
	c := NewCalculator(n, k, as)
	fmt.Println(c.Calculate())
}

