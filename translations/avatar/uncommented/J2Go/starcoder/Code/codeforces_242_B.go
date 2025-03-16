package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	a := make([]int, n)
	b := make([]int, n)
	left := 1000000000
	right := 0
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
		sc.Scan()
		b[i], _ = strconv.Atoi(sc.Text())
		left = min(left, a[i])
		right = max(right, b[i])
	}
	for i := 0; i < n; i++ {
		if left == a[i] && right == b[i] {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

