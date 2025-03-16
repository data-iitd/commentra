package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the first integer input, which represents the number of elements
	// Read the second integer input, which is the threshold value

	q1 := list.New() // Initialize queue to store the elements
	q2 := list.New() // Initialize queue to store the indices

	for i := 1; i <= n; i++ {
		var value int
		fmt.Scan(&value) // Read each element
		q1.PushBack(value) // Add it to q1
		q2.PushBack(i) // Add the corresponding index to q2
	}

	var ans int // Initialize ans to store the result

	for q1.Len() > 0 { // Continue the loop until q1 is empty
		front := q1.Front().Value.(int) // Get the front element of q1
		if front <= m { // Check if the front element of q1 is less than or equal to m
			q1.Remove(q1.Front()) // Remove the front element from q1
			ans = q2.Remove(q2.Front()).(int) // Assign the corresponding index to ans and remove it from q2
		} else { // Check if the front element of q1 is greater than m
			x := q1.Remove(q1.Front()).(int) // Remove the front element from q1
			val := x - m // Subtract m from the element
			q1.PushBack(val) // Add the result back to q1
			val2 := q2.Remove(q2.Front()).(int) // Remove the corresponding index from q2
			q2.PushBack(val2) // Add the index back to the end of q2
		}
	}

	fmt.Println(ans) // Print the index of the last remaining element
}

// <END-OF-CODE>
