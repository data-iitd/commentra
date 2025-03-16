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
	scanner.Scan()
	n := toInt(scanner.Text())
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x[i] = toInt(scanner.Text())
		scanner.Scan()
		y[i] = toInt(scanner.Text())
		scanner.Scan()
		h[i] = toInt(scanner.Text())
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

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
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

