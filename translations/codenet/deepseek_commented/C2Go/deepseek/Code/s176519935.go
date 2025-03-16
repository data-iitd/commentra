package main

import (
	"fmt"
)

// Define the heap array and its size
var heap []int
var sz int

// Function to insert a new element into the heap
func push(x int) {
	sz++
	i := sz - 1
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

// Function to remove and return the maximum element from the heap
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
	return ret
}

func main() {
	var n, m int
	var a []int
	fmt.Scan(&n, &m)
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	heap = make([]int, n)
	for i := 0; i < n; i++ {
		push(a[i])
	}
	for i := 0; i < m; i++ {
		tm := pop()
		tm /= 2
		push(tm)
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += heap[i]
	}
	fmt.Println(ans)
}

