package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i]
			b := l[j]
			right := sort.Search(n, func(x int) bool { return l[x] > a+b })
			left := sort.Search(n, func(x int) bool { return l[x] >= max(a-b, b-a) })
			tmp := max(0, right-left)
			if left <= i && i < right {
				tmp--
			}
			if left <= j && j < right {
				tmp--
			}
			ans += tmp
		}
	}
	fmt.Println(ans / 3)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

