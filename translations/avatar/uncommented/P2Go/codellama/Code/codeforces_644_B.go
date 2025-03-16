package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n, b int
	fmt.Scan(&n, &b)
	type Task struct {
		time, duration, index int
	}
	remaining := make([]Task, 0)
	running := false
	finishTime := 0
	result := make(map[int]int)
	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scan(&time, &duration)
		task := Task{time, duration, i}
		result[i] = 0
		if task.time > finishTime && len(remaining) == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && len(remaining) > 0 {
				finishTime, result = runTask(remaining, finishTime, result)
			}
			if len(remaining) < b {
				remaining = append(remaining, task)
			} else {
				result[i] = -1
			}
		}
	}
	for key := range result {
		fmt.Println(result[key])
	}
}

func runTask(remaining []Task, finishTime int, result map[int]int) (int, map[int]int) {
	taskToRun := remaining[0]
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

// 