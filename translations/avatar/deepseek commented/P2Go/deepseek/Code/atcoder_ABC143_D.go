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

			left := sort.Search(n, func(k int) bool { return l[k] >= a + b })
			right := sort.Search(n, func(k int) bool { return l[k] > max(a - b, b - a) })

			tmp := max(0, left - right)

			if left <= i {
				tmp--
			}
			if left <= j {
				tmp--
			}

			ans += tmp
		}
	}

	fmt.Fprintln(writer, ans / 3)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
