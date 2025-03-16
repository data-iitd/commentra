
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	left := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = i
	}
	answer := make([]int, n)
	for i := 0; i < q; i++ {
		var l, r, win int
		fmt.Scan(&l, &r, &win)
		for j := l; j <= r; j++ {
			if left[j] != 0 {
				answer[left[j]] = win
				left[j] = 0
			}
		}
		answer[win-1] = 0
		left[win-1] = win - 1
	}
	for i := 0; i < n; i++ {
		fmt.Print(answer[i])
	}
}

