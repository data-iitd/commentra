package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	x := make([]int, n)
	y := make([]int, n)
	h := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		y[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		h[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	for i := 0; i <= 100; i++ {
		for j := 0; j <= 100; j++ {
			ch := check(n, x, y, h, i, j)
			if ch > 0 {
				fmt.Println(i, j, ch)
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

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

