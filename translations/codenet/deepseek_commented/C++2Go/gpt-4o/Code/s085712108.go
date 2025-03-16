package main

import (
	"fmt"
	"container/heap"
)

const MOD = 7007

type QUEUE struct {
	a, b, c, tot int
}

var F = [6][3]int{
	{1, 1, 0},
	{1, 0, 1},
	{0, 1, 1},
	{2, 0, 0},
	{0, 2, 0},
	{0, 0, 2},
}

var Hash [MOD][]int

func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

func main() {
	var Push QUEUE
	Push.tot = 0
	fmt.Scan(&Push.a, &Push.b, &Push.c)

	que := &PriorityQueue{}
	heap.Init(que)
	heap.Push(que, Push)

	for que.Len() > 0 {
		Fro := heap.Pop(que).(QUEUE)
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot)
			return
		}
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if !HASH(n) {
				continue
			}
			heap.Push(que, Push)
		}
	}
}

type PriorityQueue []QUEUE

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].tot < pq[j].tot
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(QUEUE))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

// <END-OF-CODE>
