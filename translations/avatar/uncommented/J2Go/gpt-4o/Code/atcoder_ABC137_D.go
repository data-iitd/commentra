package main

import (
	"container/heap"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Job struct {
	a int
	b int
}

type JobHeap []Job

func (h JobHeap) Len() int           { return len(h) }
func (h JobHeap) Less(i, j int) bool { 
	if h[i].a == h[j].a {
		return h[i].b < h[j].b
	}
	return h[i].a < h[j].a
}
func (h JobHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.(Job))
}

func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var N, M int
	fmt.Scanln(&N, &M)

	q := &JobHeap{}
	heap.Init(q)

	for i := 0; i < N; i++ {
		var a, b int
		line := readLine()
		parts := strings.Split(line, "▁")
		a, _ = strconv.Atoi(parts[0])
		b, _ = strconv.Atoi(parts[1])
		heap.Push(q, Job{a: a, b: b})
	}

	cnt := 0
	jobQ := &JobHeap{}
	heap.Init(jobQ)

	for i := 1; i <= M; i++ {
		for q.Len() > 0 {
			job := (*q)[0]
			if job.a <= i {
				heap.Pop(q)
				heap.Push(jobQ, job.b)
			} else {
				break
			}
		}
		if jobQ.Len() > 0 {
			cnt += heap.Pop(jobQ).(int)
		}
	}

	fmt.Println(cnt)
}

func readLine() string {
	var line string
	fmt.Scanln(&line)
	return line
}
