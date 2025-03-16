

package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type Job struct {
	day    int
	salary int
}

type JobHeap []Job

func (h JobHeap) Len() int { return len(h) }

func (h JobHeap) Less(i, j int) bool {
	if h[i].day == h[j].day {
		return h[i].salary > h[j].salary
	}
	return h[i].day < h[j].day
}

func (h JobHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *JobHeap) Push(x interface{}) {
	*h = append(*h, x.(Job))
}

func (h *JobHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	var n, m int
	fmt.Fscanf(scanner, "%d %d\n", &n, &m)
	jobs := make(JobHeap, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(scanner, "%d %d\n", &jobs[i].day, &jobs[i].salary)
	}
	heap.Init(&jobs)
	var chosen []int
	for jobs.Len() > 0 {
		job := heap.Pop(&jobs).(Job)
		if len(chosen) < m && job.day <= m-len(chosen) {
			chosen = append(chosen, job.salary)
		} else if len(chosen) == m {
			if job.salary > chosen[0] {
				chosen[0] = job.salary
			}
		}
	}
	sum := 0
	for _, salary := range chosen {
		sum += salary
	}
	fmt.Println(sum)
}
