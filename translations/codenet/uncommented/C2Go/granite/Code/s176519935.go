
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, m int
	fmt.Fscanf(r, "%d%d\n", &n, &m)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d\n", &a[i])
	}
	for i := 0; i < n; i++ {
		push(a[i])
	}
	for i := 0; i < m; i++ {
		tm := pop()
		tm /= 2
		push(tm)
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += heap[i]
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

func push(x int64) {
	i := sz
	sz++
	for i > 0 {
		p := (i - 1) / 2
		if heap[p] >= x {
			break
		}
		heap[i] = heap[p]
		i = p
	}
	heap[i] = x
}

func pop() int64 {
	ret := heap[0]
	x := heap[sz-1]
	sz--
	i := 0
	for i*2+1 < sz {
		a := i*2 + 1
		b := i*2 + 2
		if b < sz && heap[b] > heap[a] {
			a = b
		}
		if heap[a] <= x {
			break
		}
		heap[i] = heap[a]
		i = a
	}
	heap[i] = x
	return ret
}

var (
	sz int
	heap = make([]int64, 100000)
)

