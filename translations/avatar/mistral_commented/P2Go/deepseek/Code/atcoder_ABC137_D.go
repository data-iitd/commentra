package main

import (
	"container/heap"
	"fmt"
)

// Employee struct to hold day and salary
type Employee struct {
	day   int
	salary int
}

// MinHeap to implement heap interface
type MinHeap []Employee

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i].day < h[j].day }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Employee))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize an empty heap
	h := &MinHeap{}
	heap.Init(h)

	// Read employee details and push to heap
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		heap.Push(h, Employee{day, salary})
	}

	// Initialize an empty list for storing employees
	y := &MinHeap{}
	heap.Init(y)

	// Simulation loop to check if an employee can be added to the list 'y'
	for h.Len() > 0 {
		// Pop the employee with minimum day from the heap 'h'
		emp := heap.Pop(h).(Employee)
		d := emp.day
		s := emp.salary

		// Calculate the remaining capacity in the list 'y'
		r := m - y.Len()

		// Check if the remaining capacity is enough to add the current employee
		if r >= d {
			// If yes, add the salary of the employee to the list 'y'
			heap.Push(y, Employee{s, 0})
		} else {
			// If no, remove an employee with minimum salary from the list 'y' and add the current employee
			if y.Len() > 0 {
				heap.Pop(y)
			}
			heap.Push(y, Employee{s, 0})
		}
	}

	// Calculate the sum of salaries of employees in the list 'y'
	sum := 0
	for _, emp := range *y {
		sum += emp.salary
	}

	// Print the sum of salaries
	fmt.Println(sum)
}
