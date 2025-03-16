
package main

import (
	"fmt"
	"container/heap"
)

func main() {
	var N int
	fmt.Scan(&N)
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}
	sum := 0
	q := make(PriorityQueue, 0)
	heap.Init(&q)
	for i := 0; i < len(arr); i++ {
		heap.Push(&q, arr[i])
		if arr[i] <= q[0] {
			sum++
		}
	}
	fmt.Println(sum)
}

type PriorityQueue []int

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

