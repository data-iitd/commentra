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

type TaskQueue []*Task

func (tq TaskQueue) Len() int {
	return len(tq)
}

func (tq TaskQueue) Less(i, j int) bool {
	return tq[i].time < tq[j].time
}

func (tq *TaskQueue) Swap(i, j int) {
	(*tq)[i], (*tq)[j] = (*tq)[j], (*tq)[i]
}

func (tq *TaskQueue) Push(x interface{}) {
	*tq = append(*tq, x.(*Task))
}

func (tq *TaskQueue) Pop() interface{} {
	old := *tq
	n := len(old)
	task := old[n-1]
	*tq = old[0 : n-1]
	return task
}

func runTask(remaining *TaskQueue, finishTime int, result map[int]int) (int, map[int]int) {
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

	remaining := &TaskQueue{}
	heap.Init(remaining)
	finishTime := 0
	result := make(map[int]int)

	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)
		task := &Task{time: time, duration: duration, index: i}
		result[i] = 0

		if time > finishTime && remaining.Len() == 0 {
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
