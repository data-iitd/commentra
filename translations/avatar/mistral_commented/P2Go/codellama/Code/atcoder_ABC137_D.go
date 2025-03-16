package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declaring variables for number of days and number of employees
	var n, m int

	// Taking input of number of days and number of employees
	fmt.Scan(&n, &m)

	// Declaring empty lists for storing days and salaries
	x := make([]int, 0)
	y := make([]int, 0)

	// Iterating through each employee and adding their details to the heap 'x'
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Scan(&day, &salary)
		// Adding employee details as a tuple to the heap 'x' with negative day and salary values
		x = append(x, -day)
		x = append(x, -salary)
	}

	// Simulation loop to check if an employee can be added to the list 'y'
	for len(x) > 0 {
		// Popping the employee with minimum negative day from the heap 'x'
		d := -x[0]
		s := -x[1]
		x = x[2:]

		// Calculating the remaining capacity in the list 'y'
		r := m - len(y)

		// Checking if the remaining capacity is enough to add the current employee
		if r >= d {
			// If yes, adding the salary of the employee to the list 'y'
			y = append(y, s)
		} else {
			// If no, removing an employee with minimum salary from the list 'y' and adding the current employee
			y = append(y, s)
			y = y[:len(y)-1]
		}
	}

	// Printing the sum of salaries of employees in the list 'y'
	fmt.Println(sum(y))
}

func sum(arr []int) int {
	sum := 0
	for _, v := range arr {
		sum += v
	}
	return sum
}

