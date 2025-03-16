package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	go func() {
		var n, k int
		as := []int{}
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Split(bufio.ScanWords)
		scanner.Scan()
		n, _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		k, _ = strconv.Atoi(scanner.Text())
		for i := 0; i < n; i++ {
			scanner.Scan()
			as = append(as, parseInt(scanner.Text())-1)
		}
		fmt.Println(newCalculator(n, k, as).calculate())
	}()
}

type Calculator struct {
	k       int
	answer  int
	isCalc  bool
	lists   [][]int
}

func newCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{k: k}
	c.lists = make([][]int, n)
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

func (c *Calculator) calculate() int {
	if !c.isCalc {
		c.dfs(0, 0)
		c.isCalc = true
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

func parseInt(s string) int {
	num, _ := strconv.Atoi(s)
	return num
}

