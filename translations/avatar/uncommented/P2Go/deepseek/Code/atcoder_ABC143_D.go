package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &l[i])
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i]
			b := l[j]
			right := sort.SearchInts(l, a+b)
			left := sort.SearchInts(l, max(a-b, b-a))
			tmp := max(0, right-left)
			if left <= i && i < right {
				tmp -= 1
			}
			if left <= j && j < right {
				tmp -= 1
			}
			ans += tmp
		}
	}
	fmt.Fprintln(writer, ans/3)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
