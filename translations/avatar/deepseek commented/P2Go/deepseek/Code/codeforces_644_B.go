package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Task struct {
	time     int
	duration int
	index    int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())

	var remaining = make([]Task, 0)
	var running bool
	var finishTime int
	var result = make(map[int]int)

	for i := 0; i < n; i++ {
		scanner.Scan()
		time, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		duration, _ := strconv.Atoi(scanner.Text())
		task := Task{time, duration, i}
		result[i] = 0
		if task.time > finishTime && len(remaining) == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && len(remaining) > 0 {
				finishTime, result = runTask(remaining, finishTime)
			}
			if len(remaining) < b {
				remaining = append(remaining, task)
			} else {
				result[i] = -1
			}
		}
	}

	for len(remaining) > 0 {
		finishTime, result = runTask(remaining, finishTime)
	}

	for _, value := range result {
		fmt.Println(value)
	}
}

func runTask(remaining []Task, finishTime int) (int, map[int]int) {
	taskToRun := remaining[0]
	remaining = remaining[1:]
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

