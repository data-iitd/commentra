package main

import (
	"container/heap"
	"fmt"
)

type Task struct {
	time     int
	duration int
	index    int
}

type PriorityQueue []*Task

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].time < pq[j].time
}

func (pq *PriorityQueue) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Task))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	task := old[n-1]
	*pq = old[0 : n-1]
	return task
}

func runTask(remaining *PriorityQueue, finishTime int, result map[int]int) (int, map[int]int) {
	taskToRun := heap.Pop(remaining).(*Task)
	finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
	result[taskToRun.index] = finishTime
	return finishTime, result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, b int
	fmt.Scan(&n, &b)

	remaining := &PriorityQueue{}
	heap.Init(remaining)
	running := false
	finishTime := 0
	result := make(map[int]int)

	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)
		task := &Task{time: time, duration: duration, index: i}
		result[i] = 0

		if time > finishTime && remaining.Len() == 0 {
			running = true
			finishTime = time + duration
			result[i] = finishTime
		} else {
			if time >= finishTime && remaining.Len() > 0 {
				finishTime, result = runTask(remaining, finishTime, result)
			}
			if remaining.Len() < b {
				heap.Push(remaining, task)
			} else {
				result[i] = -1
			}
		}
	}

	for remaining.Len() > 0 {
		finishTime, result = runTask(remaining, finishTime, result)
	}

	for key := range result {
		fmt.Println(result[key])
	}
}

// <END-OF-CODE>
