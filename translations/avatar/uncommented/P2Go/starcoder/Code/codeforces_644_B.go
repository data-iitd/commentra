package main
import (
"fmt"
"container/heap"
)
type Task struct {
time int
duration int
index int
}
func (t Task) Less(i, j int) bool {
return t[i].time < t[j].time
}
func (t Task) Swap(i, j int) {
t[i], t[j] = t[j], t[i]
}
func (t *Task) Push(x interface{}) {
*t = x.(Task)
}
func (t *Task) Pop() interface{} {
old := *t
*t = t[0]
return old
}
func main() {
n, b := 0, 0
fmt.Scanf("%d %d", &n, &b)
tasks := make([]Task, n)
for i := 0; i < n; i++ {
fmt.Scanf("%d %d", &tasks[i].time, &tasks[i].duration)
tasks[i].index = i
}
heap.Init(&tasks)
running := false
finishTime := 0
result := make([]int, n)
for i := 0; i < n; i++ {
task := heap.Pop(&tasks).(Task)
if task.time > finishTime && len(tasks) == 0 {
running = true
finishTime = task.time + task.duration
result[task.index] = finishTime
} else {
if task.time >= finishTime && len(tasks) > 0 {
task = heap.Pop(&tasks).(Task)
finishTime = task.time + task.duration
result[task.index] = finishTime
}
if len(tasks) < b {
heap.Push(&tasks, task)
} else {
result[task.index] = -1
}
}
}
for _, v := range result {
fmt.Println(v)
}
}
