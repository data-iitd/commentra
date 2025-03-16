
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MAX = 100

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		x := make([]int, n)
		y := make([]int, n)
		h := make([]int, n)
		for i := 0; i < n; i++ {
			if!scanner.Scan() {
				break
			}
			x[i], _ = strconv.Atoi(scanner.Text())
			if!scanner.Scan() {
				break
			}
			y[i], _ = strconv.Atoi(scanner.Text())
			if!scanner.Scan() {
				break
			}
			h[i], _ = strconv.Atoi(scanner.Text())
		}
		for i := 0; i <= MAX; i++ {
			for j := 0; j <= MAX; j++ {
				ch := check(n, x, y, h, i, j)
				if ch > 0 {
					fmt.Printf("%d %d %d\n", i, j, ch)
				}
			}
		}
	}
}

func check(n int, x []int, y []int, h []int, cx int, cy int) int {
	ch := -1
	for i := 0; i < n; i++ {
		if h[i] > 0 {
			ch = abs(x[i]-cx) + abs(y[i]-cy) + h[i]
			break
		}
	}
	for i := 0; i < n; i++ {
		if h[i]!= max(ch-abs(x[i]-cx)-abs(y[i]-cy), 0) {
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

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

