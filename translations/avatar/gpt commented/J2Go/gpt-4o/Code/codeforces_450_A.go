package main

import (
	"fmt"
	"container/list"
)

func main() {
	// Create a scanner to read input from the user
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize two queues: one for the values and one for their original indices
	q1 := list.New()
	q2 := list.New()

	// Populate the queues with input values and their corresponding indices
	for i := 1; i <= n; i++ {
		var value int
		fmt.Scan(&value)
		q1.PushBack(value) // Add the value to the first queue
		q2.PushBack(i)     // Add the index to the second queue
	}

	// Variable to store the final answer (the index of the last processed element)
	var ans int

	// Process the elements in the queue until it is empty
	for q1.Len() > 0 {
		frontValue := q1.Front().Value.(int)
		if frontValue <= m {
			// If yes, remove it from q1 and update the answer with the corresponding index from q2
			ans = q2.Front().Value.(int)
			q1.Remove(q1.Front())
			q2.Remove(q2.Front())
		} else {
			// If the front element is greater than m
			x := q1.Remove(q1.Front()).(int)
			val := x - m
			q1.PushBack(val) // Add the reduced value back to q1

			// Remove the index from q2 and add it back to maintain the order
			val2 := q2.Remove(q2.Front()).(int)
			q2.PushBack(val2)
		}
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
