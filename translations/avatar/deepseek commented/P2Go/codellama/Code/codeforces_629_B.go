
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define the maximum number of time slots
	N := 368

	// Initialize lists to store changes for males and females
	m := make([]int, N)
	f := make([]int, N)

	// Read the number of operations
	numOperations, _ := strconv.Atoi(os.Args[1])

	// Read each line, strip newline, and split into gender, start time, and end time
	for i := 0; i < numOperations; i++ {
		line := strings.Split(os.Args[2+i], " ")
		gender := line[0]
		startTime, _ := strconv.Atoi(line[1])
		endTime, _ := strconv.Atoi(line[2])
		endTime++

		// Update the changes in the lists based on gender
		if gender == "M" {
			m[startTime] += 2
			m[endTime] -= 2
		} else {
			f[startTime] += 2
			f[endTime] -= 2
		}
	}

	// Initialize variables to store the maximum number of people and the current number of people
	a, b, c := 0, 0, 0

	// Calculate the cumulative sum of changes and find the maximum number of people at any time slot
	for i := 0; i < N; i++ {
		a += m[i]
		b += f[i]
		if a < b {
			a = b
		}
		if a > c {
			c = a
		}
	}

	// Print the maximum number of people at any time slot
	fmt.Println(c)
}

