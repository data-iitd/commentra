package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of days (n) and the maximum number of jobs (m) from input
	n, m := readInput()

	// Initialize two heaps: one for jobs (x) and one for selected salaries (y)
	x := make([]int, 0)
	y := make([]int, 0)

	// Read the job details for n days
	for i := 0; i < n; i++ {
		// For each day, read the day number and salary
		day, salary := readInput()
		// Push the negative of day and salary onto the heap to create a max-heap
		heapq.Push(x, -day)
		heapq.Push(x, -salary)
	}

	// Process the jobs in the heap until it's empty
	for x.Len() > 0 {
		// Pop the job with the highest day and salary (due to negation)
		d := heapq.Pop(x).(int)
		s := heapq.Pop(x).(int)

		// Calculate the remaining capacity for jobs
		r := m - len(y)

		// If there is enough capacity to take the job
		if r >= -d {
			// Add the salary to the selected salaries heap
			heapq.Push(y, -s)
		} else {
			// If capacity is full, replace the lowest salary if the new salary is higher
			heapq.Push(y, -s)
			heapq.Pop(y) // Remove the lowest salary from the heap
	}

	// Output the total sum of selected salaries
	fmt.Println(sum(y))
}

func readInput() (int, int) {
	// Read the number of days (n) and the maximum number of jobs (m) from input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)
	return n, m
}

func sum(y []int) int {
	sum := 0
	for _, v := range y {
		sum += v
	}
	return sum
}

