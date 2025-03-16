package main

import (
	"fmt"
	"container/list"
)

type Task struct {
	time     int
	duration int
	index    int
}

func runTask(remaining *list.List, finishTime int) (int, map[int]int) {
	taskToRun := remaining.Remove(remaining.Front()).(*Task)
	finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
	result[taskToRun.index] = finishTime
	return finishTime, result
}

var result = make(map[int]int)

func main() {
	var n, b int
	fmt.Scan(&n, &b)

	remaining := list.New()
	var finishTime int

	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)
		task := &Task{time, duration, i}
		result[i] = 0
		if task.time > finishTime && remaining.Len() == 0 {
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && remaining.Len() > 0 {
				var newFinishTime int
				newFinishTime, result = runTask(remaining, finishTime)
				finishTime = newFinishTime
			}
			if remaining.Len() < b {
				remaining.PushBack(task)
			} else {
				result[i] = -1
			}
		}
	}

	for remaining.Len() > 0 {
		var newFinishTime int
		newFinishTime, result = runTask(remaining, finishTime)
		finishTime = newFinishTime
	}

	for _, value := range result {
		fmt.Println(value)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

