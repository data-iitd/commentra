package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Task struct {
	time     int
	duration int
	index    int
}

func main() {
	var n, b int
	fmt.Scanf("%d %d", &n, &b)
	tasks := make([]Task, n)
	result := make(map[int]int)
	for i := 0; i < n; i++ {
		var time, duration int
		fmt.Scanf("%d %d", &time, &duration)
		tasks[i] = Task{time, duration, i}
		result[i] = 0
	}
	var finishTime int
	var running bool
	for i := 0; i < n; i++ {
		task := tasks[i]
		if task.time > finishTime && len(tasks) == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && len(tasks) > 0 {
				finishTime, result = runTask(tasks, finishTime)
			}
			if len(tasks) < b {
				tasks = append(tasks, task)
			} else {
				result[i] = -1
		}
	}
	for key := range result {
		fmt.Println(result[key])
	}
}

func runTask(tasks []Task, finishTime int) (int, map[int]int) {
	task := tasks[0]
	finishTime = max(finishTime, task.time) + task.duration
	result[task.index] = finishTime
	tasks = tasks[1:]
	return finishTime, result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

