
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of jobs and the maximum number of days available
	n, m := readInts()

	// Initialize lists to store job days and salaries
	x := make([]int, 0)
	y := make([]int, 0)

	// Read each job's day and salary, and push them into the heap x
	for i := 0; i < n; i++ {
		day, salary := readInts()
		// Push the day and salary as negative values to simulate a max-heap
		x = append(x, -day)
		x = append(x, -salary)
	}

	// Process the jobs in the order of their deadlines
	for len(x) > 0 {
		// Pop the job with the largest deadline (negated values)
		d, s := x[0], x[1]
		x = x[2:]

		// Calculate the remaining days available for new jobs
		r := m - len(y)

		// If there are enough days to accommodate this job
		if r >= -d {
			// Add the salary to the list of chosen salaries
			y = append(y, -s)
		} else {
			// If not enough days, check if we need to remove the smallest salary
			y = append(y, -s)
			y = y[:len(y)-1]
		}
	}

	// Output the sum of the chosen salaries
	fmt.Println(sum(y))
}

func readInts() (int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	n, _ := strconv.Atoi(line)
	scanner.Scan()
	line = scanner.Text()
	m, _ := strconv.Atoi(line)
	return n, m
}

func sum(x []int) int {
	s := 0
	for _, v := range x {
		s += v
	}
	return s
}

// 