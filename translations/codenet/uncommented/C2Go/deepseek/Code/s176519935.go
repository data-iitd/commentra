package main

import (
	"fmt"
)

var heap []int64
var sz int

func push(x int) {
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

func pop() int {
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
	return int(ret)
}

func main() {
	var n, m, i, j int
	var a []int64
	fmt.Scan(&n, &m)
	a = make([]int64, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i = 0; i < n; i++ {
		push(int(a[i]))
	}
	for i = 0; i < m; i++ {
		tm := int64(pop())
		tm /= 2
		push(int(tm))
	}
	var ans int64
	ans = 0
	for i = 0; i < n; i++ {
		ans += heap[i]
	}
	fmt.Println(ans)
}

