
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := make([]int, 0)

	// Read the number of elements (n) and the threshold value (m)
	n, _ := strconv.Atoi(os.Args[1])
	m, _ := strconv.Atoi(os.Args[2])

	// Initialize two queues: one for the values and one for their original indices
	q1 := make([]int, 0)
	q2 := make([]int, 0)

	// Populate the queues with input values and their corresponding indices
	for i := 1; i <= n; i++ {
		q1 = append(q1, i) // Add the value to the first queue
		q2 = append(q2, i) // Add the index to the second queue
	}

	// Variable to store the final answer (the index of the last processed element)
	ans := 0

	// Process the elements in the queue until it is empty
	for len(q1) > 0 {
		// Check if the front element of q1 is less than or equal to m
		if q1[0] <= m {
			// If yes, remove it from q1 and update the answer with the corresponding index from q2
			q1 = q1[1:]
			ans = q2[0]
			q2 = q2[1:]
		}
		// If the front element is greater than m
		if q1[0] > m {
			// Remove the element, reduce it by m, and add it back to q1
			x := q1[0]
			val := x - m
			q1 = append(q1[1:], val)

			// Remove the index from q2 and add it back to maintain the order
			val2 := q2[0]
			q2 = append(q2[1:], val2)
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

