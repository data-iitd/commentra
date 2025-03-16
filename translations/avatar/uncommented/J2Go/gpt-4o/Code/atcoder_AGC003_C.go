package main

import (
	"container/heap"
	"fmt"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var N int
	fmt.Scan(&N)

	mapIndex := make(map[int]int)
	nums := &IntHeap{}
	heap.Init(nums)

	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp)
		heap.Push(nums, tmp)
		mapIndex[tmp] = i
	}

	bin := 0
	diff := 0

	for nums.Len() > 0 {
		num := heap.Pop(nums).(int)
		idx := mapIndex[num]
		if (bin%2) != (idx%2) {
			diff++
		}
		bin++
		bin %= 2
	}

	ans := diff / 2
	fmt.Println(ans)
}

// <END-OF-CODE>
