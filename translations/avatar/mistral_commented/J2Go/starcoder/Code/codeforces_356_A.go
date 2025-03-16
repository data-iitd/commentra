
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// <START-OF-CODE>

func main() {
	// Initializing FastReader for reading input
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(in, &n)
	left := make(sort.IntSlice, n)
	answer := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = i
		answer[i] = -1
	}
	var q int
	fmt.Fscan(in, &q)
	for q > 0 {
		l, r, win := 0, 0, 0
		fmt.Fscan(in, &l, &r, &win)
		l--
		r--
		win--
		for left[l] <= r {
			curr := left[l]
			answer[curr] = win
			left = append(left[:l], left[l+1:]...)
		}
		answer[win] = 0
		left = append(left, win)
		q--
	}
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i]))
		if i!= n-1 {
			ans.WriteByte(' ')
		}
	}
	fmt.Println(ans.String())
}

// 