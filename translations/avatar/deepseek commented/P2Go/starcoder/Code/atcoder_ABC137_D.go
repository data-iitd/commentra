
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Read the number of jobs and the maximum number of days available
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)

	// Initialize lists to store job days and salaries
	x := make([]int, n)
	y := make([]int, 0)

	// Read each job's day and salary, and push them into the heap x
	for i := 0; i < n; i++ {
		var day, salary int
		fmt.Fscan(reader, &day, &salary)
		// Push the day and salary as negative values to simulate a max-heap
		x[i] = -day
		y = append(y, -salary)
	}

	// Process the jobs in the order of their deadlines
	for len(x) > 0 {
		// Pop the job with the largest deadline (negated values)
		d := x[0]
		s := y[0]
		x = x[1:]
		y = y[1:]

		// Calculate the remaining days available for new jobs
		r := m - len(y)

		// If there are enough days to accommodate this job
		if r >= -d {
			// Add the salary to the list of chosen salaries
			y = append(y, -s)
		} else {
			// If not enough days, check if we need to remove the smallest salary
			y = append(y, -s)
			y = y[1:]
		}
	}

	// Output the sum of the chosen salaries
	fmt.Println(sum(y))
}

func sum(x []int) int {
	var sum int
	for _, v := range x {
		sum += v
	}
	return sum
}

