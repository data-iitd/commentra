

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type MyRunnable struct{}

func (mr *MyRunnable) Run() {
	n, k := readTwoInt()
	as := make([]int, n)
	for i := 0; i < n; i++ {
		as[i] = readInt() - 1
	}
	fmt.Println(newCalculator(n, k, as).calculate())
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	return n
}

func readTwoInt() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	m, _ := strconv.Atoi(sc.Text())
	return n, m
}

type Calculator struct {
	k        int
	answer   int
	isCalculate bool
	lists    [][]int
}

func newCalculator(n int, k int, as []int) *Calculator {
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

func (c *Calculator) dfs(a int, pre int) int {
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

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	mr := &MyRunnable{}
	mr.Run()
}

