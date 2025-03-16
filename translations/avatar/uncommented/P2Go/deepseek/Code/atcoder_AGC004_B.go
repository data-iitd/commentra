package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, x int
	fmt.Fscan(reader, &n, &x)

	var a []int
	for i := 0; i < n; i++ {
		var ai int
		fmt.Fscan(reader, &ai)
		a = append(a, ai)
	}

	b := make([][]int, n)
	for i := 0; i < n; i++ {
		b[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		m := a[i]
		for j := 0; j < n; j++ {
			k := i - j
			if k < 0 {
				k += n
			}
			m = min(m, a[k])
			b[j][i] = m
		}
	}

	m := 1000000000000000
	for i := 0; i < n; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			sum += b[i][j]
		}
		m = min(m, sum+x*i)
	}

	fmt.Fprintln(writer, m)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
