
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type MyRunnable struct {
}

func (mr *MyRunnable) run() {
	var n, k int
	var as []int
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	k, _ = strconv.Atoi(sc.Text())
	for i := 0; i < n; i++ {
		sc.Scan()
		a, _ := strconv.Atoi(sc.Text())
		as = append(as, a-1)
	}
	fmt.Println(NewCalculator(n, k, as).calculate())
}

func (mr *MyRunnable) Run() {
	mr.run()
}

type Calculator struct {
	k         int
	answer    int
	isCalculate bool
	lists     [][]int
}

func NewCalculator(n, k int, as []int) *Calculator {
	c := &Calculator{
		k: k,
	}
	for i := 0; i < n; i++ {
		c.lists = append(c.lists, []int{})
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
	mr := &MyRunnable{}
	mr.Run()
}

