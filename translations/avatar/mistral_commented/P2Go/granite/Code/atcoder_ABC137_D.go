
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"strconv"
)

// Employee struct to store employee details
type Employee struct {
	Day    int
	Salary int
}

// EmployeeHeap struct to implement min heap
type EmployeeHeap []*Employee

// Len method to get the length of the heap
func (h EmployeeHeap) Len() int { return len(h) }

// Less method to compare two employees based on their salaries
func (h EmployeeHeap) Less(i, j int) bool { return h[i].Salary < h[j].Salary }

// Swap method to swap two employees in the heap
func (h EmployeeHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

// Push method to add an employee to the heap
func (h *EmployeeHeap) Push(x interface{}) { *h = append(*h, x.(*Employee)) }

// Pop method to remove an employee from the heap
func (h *EmployeeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	// Taking input of number of days and number of employees
	data := bufio.NewScanner(os.Stdin)
	data.Scan()
	n, m := mustParseInt(data.Text(), 2)

	// Initializing empty lists for storing days and salaries
	x := make(EmployeeHeap, 0)
	y := make(EmployeeHeap, 0)

	// Iterating through each employee and adding their details to the heap 'x'
	for i := 0; i < n; i++ {
		data.Scan()
		day, salary := mustParseInt(data.Text(), 2)
		// Adding employee details as a struct to the heap 'x' with negative day and salary values
		heap.Push(&x, &Employee{-day, -salary})
	}

	// Simulation loop to check if an employee can be added to the list 'y'
	for x.Len() > 0 {
		// Popping the employee with minimum negative day from the heap 'x'
		e := heap.Pop(&x).(*Employee)
		// Calculating the remaining capacity in the list 'y'
		r := m - y.Len()
		// Checking if the remaining capacity is enough to add the current employee
		if r >= e.Day {
			// If yes, adding the salary of the employee to the list 'y'
			heap.Push(&y, e)
		} else {
			// If no, removing an employee with minimum salary from the list 'y' and adding the current employee
			heap.Push(&y, e)
			heap.Pop(&y)
		}
	}

	// Printing the sum of salaries of employees in the list 'y'
	sum := 0
	for y.Len() > 0 {
		sum += heap.Pop(&y).(*Employee).Salary
	}
	fmt.Println(sum)
}

// mustParseInt function to parse input string to integer
func mustParseInt(s string, n int) (int, int) {
	a, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return a, n
}

// 