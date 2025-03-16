
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"container/list"
)

type Task struct {
	time     int
	duration int
	index    int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	b, _ := strconv.Atoi(read(reader))
	remaining := list.New()
	result := make(map[int]int)
	running := false
	finishTime := 0
	for i := 0; i < n; i++ {
		time, _ := strconv.Atoi(read(reader))
		duration, _ := strconv.Atoi(read(reader))
		task := &Task{time: time, duration: duration, index: i}
		result[i] = 0
		if task.time > finishTime && remaining.Len() == 0 {
			running = true
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else if task.time >= finishTime && remaining.Len() > 0 {
			finishTime, result = runTask(remaining, finishTime)
			if remaining.Len() < b {
				remaining.PushBack(task)
			} else {
				result[i] = -1
			}
		}
	}
	for remaining.Len() > 0 {
		finishTime, result = runTask(remaining, finishTime)
	}
	for _, v := range result {
		fmt.Println(v)
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func runTask(remaining *list.List, finishTime int) (int, map[int]int) {
	task := remaining.Front()
	remaining.Remove(task)
	finishTime = max(finishTime, task.Value.(*Task).time) + task.Value.(*Task).duration
	result[task.Value.(*Task).index] = finishTime
	return finishTime, result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

