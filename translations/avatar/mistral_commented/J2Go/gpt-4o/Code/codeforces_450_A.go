package main // Defining the main package

import (
	"container/list" // Importing the container/list package for queue implementation
	"fmt"           // Importing the fmt package for formatted I/O
)

func main() { // Starting the main function
	var n, m int
	fmt.Scan(&n) // Reading the first integer n from the standard input
	fmt.Scan(&m) // Reading the second integer m from the standard input

	q1 := list.New() // Creating a new doubly linked list for queue q1
	q2 := list.New() // Creating a new doubly linked list for queue q2

	for i := 1; i <= n; i++ { // Iterating through the input values from 1 to n
		var value int
		fmt.Scan(&value) // Reading the next integer value
		q1.PushBack(value) // Adding the next integer value to the queue q1
		q2.PushBack(i)     // Adding the current index value to the queue q2
	}

	var ans int // Initializing the answer variable to 0
	for q1.Len() > 0 { // Starting the loop to process the queues until q1 is empty
		frontQ1 := q1.Front() // Getting the front value of q1
		if frontQ1.Value.(int) <= m { // Checking if the next value in q1 is less than or equal to m
			ans = q2.Front().Value.(int) // Getting the corresponding index value from q2
			q1.Remove(frontQ1) // Removing the next value from q1
			q2.Remove(q2.Front()) // Removing the corresponding index value from q2
		} else { // If the next value in q1 is greater than m
			x := frontQ1.Value.(int) // Getting the next value from q1
			val := x - m // Calculating the new value by subtracting m from the next value
			q1.Remove(frontQ1) // Removing the next value from q1
			q1.PushBack(val) // Adding the new value back to the queue q1
			val2 := q2.Front() // Getting the corresponding index value from q2
			q2.Remove(val2) // Removing the corresponding index value from q2
			q2.PushBack(val2.Value) // Adding the index value back to the queue q2
		}
	}

	fmt.Println(ans) // Printing the final answer
}

// <END-OF-CODE>
