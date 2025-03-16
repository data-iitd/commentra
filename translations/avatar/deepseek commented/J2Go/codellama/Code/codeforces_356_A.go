
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
	for q > 0 {
		q--
		var l, r, win int
		fmt.Scan(&l, &r, &win)
		l--
		r--
		win--
		for left[l] <= r {
			curr := left[l]
			answer[curr] = win
			left[l] = n
			l++
		}
		answer[win] = 0
		left[win] = l
	}
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i]))
	}
	fmt.Println(ans.String())
}

