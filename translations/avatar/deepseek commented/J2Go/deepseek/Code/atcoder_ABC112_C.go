package main

import (
	"bufio"
	"fmt"
	"os"
)

const MAX = 100

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n int
	fmt.Scan(&n)

	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i], &h[i])
	}

	for i := 0; i <= MAX; i++ {
		for j := 0; j <= MAX; j++ {
			ch := check(n, x, y, h, i, j)
			if ch > 0 {
				fmt.Println(i, j, ch)
			}
		}
	}
}

func check(n int, x, y, h []int, cx, cy int) int {
	ch := -1
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = abs(x[i]-cx) + abs(y[i]-cy) + h[i]
			break
		}
	}

	for i := 0; i < n; i++ {
		if h[i] != max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
			return -1
		}
	}
	return ch
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

