
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n-1)
		for j := 0; j < n-1; j++ {
			fmt.Fscanf(in, "%d", &a[i][j])
		}
		fmt.Fscanf(in, "\n")
	}
	e1 := make([]int, n*n)
	e2 := make([]int, n*n)
	d := make([]int, n*n)
	b := make([]bool, n*n)
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				fmt.Fprintln(out, -1)
				return
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		from := p(i, a[i][0])
		now := f(from, e1, e2, d, b)
		if now < 0 {
			fmt.Fprintln(out, -1)
			return
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

func p(a, b int) int {
	if a < b {
		return a + b*n
	} else {
		return b + a*n
	}
}

func f(from int, e1, e2, d []int, b []bool) int {
	if b[from] {
		return -1
	}
	if d[from]!= 0 {
		return d[from]
	}
	b[from] = true
	to := e1[from]
	max := 0
	if to!= 0 {
		now := f(to, e1, e2, d, b)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to!= 0 {
		now := f(to, e1, e2, d, b)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	b[from] = false
	d[from] = max + 1
	return d[from]
}

