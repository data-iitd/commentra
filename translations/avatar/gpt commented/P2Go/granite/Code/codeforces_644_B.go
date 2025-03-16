
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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of tasks (n) and the maximum number of concurrent tasks (b):")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	n, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	remaining := make(chan *Task, b)
	running := false
	finishTime := 0
	result := make(map[int]int)

	runTask := func(remaining chan *Task, finishTime int) (int, map[int]int) {
		task := <-remaining
		finishTime = int(math.Max(float64(finishTime), float64(task.time))) + task.duration
		result[task.index] = finishTime
		return finishTime, result
	}

	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		parts := strings.Split(input, " ")
		time, _ := strconv.Atoi(parts[0])
		duration, _ := strconv.Atoi(parts[1])
		task := &Task{time: time, duration: duration, index: i}
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
				remaining <- task
			} else {
				result[i] = -1
			}
		}
	}

	for len(remaining) > 0 {
		finishTime, result = runTask(remaining, finishTime)
	}

	for _, v := range result {
		fmt.Println(v)
	}
}
