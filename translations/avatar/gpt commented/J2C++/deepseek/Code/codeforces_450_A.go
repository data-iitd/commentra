package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements (n) and the threshold value (m)
	scanner.Scan()
	n := 0
	fmt.Sscan(scanner.Text(), &n)
	scanner.Scan()
	m := 0
	fmt.Sscan(scanner.Text(), &m)
	
	// Initialize two queues: one for the values and one for their original indices
	type pair struct {
		value int
		index int
	}
	q1 := []pair{}
	q2 := []int{}
	
	// Populate the queues with input values and their corresponding indices
	for i := 1; i <= n; i++ {
		scanner.Scan()
		val := 0
		fmt.Sscan(scanner.Text(), &val)
		q1 = append(q1, pair{val, i})
		q2 = append(q2, i)
	}
	
	// Variable to store the final answer (the index of the last processed element)
	ans := 0
	
	// Process the elements in the queue until it is empty
	for len(q1) > 0 {
		// Check if the front element of q1 is less than or equal to m
		if q1[0].value <= m {
			// If yes, remove it from q1 and update the answer with the corresponding index from q2
			ans = q2[0]
			q1 = q1[1:]
			q2 = q2[1:]
		} else if q1[0].value > m {
			// Remove the element, reduce it by m, and add it back to q1
			x := q1[0].value
			q1 = q1[1:]
			val := x - m
			q1 = append(q1, pair{val, 0})
			
			// Remove the index from q2 and add it back to maintain the order
			val2 := q2[0]
			q2 = q2[1:]
			q2 = append(q2, val2)
		}
	}
	
	// Output the final answer
	fmt.Println(ans)
}
