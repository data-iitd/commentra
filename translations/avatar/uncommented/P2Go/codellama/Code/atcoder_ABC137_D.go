package main

import (
	"container/heap"
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	x := make([]int, n)
	y := make([]int, m)
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		x[i] = -day
		y[i] = -salary
	}
	heap.Init(&x)
	heap.Init(&y)
	for x.Len() > 0 {
		d := heap.Pop(&x).(int)
		s := heap.Pop(&y).(int)
		r := m - len(y)
		if r >= -d {
			heap.Push(&y, -s)
		} else {
			heap.Push(&y, -s)
			heap.Pop(&y)
		}
	}
	fmt.Println(sum(y))
}

func sum(y []int) int {
	var s int
	for _, v := range y {
		s += -v
	}
	return s
}

// END-OF-CODE
