
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
    n, b := readTwoNumbers(reader)
    remaining := make(chan *Task, b)
    running := false
    finishTime := 0
    result := make(map[int]int)
    for i := 0; i < n; i++ {
        time, duration := readTwoNumbers(reader)
        task := &Task{time, duration, i}
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

func readTwoNumbers(reader *bufio.Reader) (int, int) {
    res := strings.Split(readLine(reader), " ")
    a, _ := strconv.Atoi(res[0])
    b, _ := strconv.Atoi(res[1])
    return a, b
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.Trim(string(str), " \r\n")
    }
    return ""
}

func runTask(remaining chan *Task, finishTime int) (int, map[int]int) {
    task := <-remaining
    finishTime = max(finishTime, task.time) + task.duration
    result[task.index] = finishTime
    return finishTime, result
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}

