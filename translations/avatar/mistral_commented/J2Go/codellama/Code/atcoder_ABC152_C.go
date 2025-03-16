package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize System.out for printing output
	fmt.Println(solve()) // Calling solve method to get the solution and print it
}

// solve method to find the solution
func solve() int {
	sc := bufio.NewScanner(os.Stdin) // Creating a new Scanner object to read input

	var N int // Reading the number of elements in the array
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())

	arr := make([]int, N) // Creating an integer array of size N

	// Using for loop to read and store elements in the array
	for i := 0; i < N; i++ {
		sc.Scan()
		arr[i], _ = strconv.Atoi(sc.Text()) // Reading an integer and storing it in the array at the current index
	}

	sum := 0 // Initializing sum variable to 0
	q := make([]int, 0) // Creating an empty PriorityQueue

	// Using for loop to iterate through the array
	for i := 0; i < len(arr); i++ {
		q = append(q, arr[i]) // Adding the current element to the queue

		// Checking if the current element is smaller than or equal to the top element of the queue
		if arr[i] <= q[0] {
			sum++ // Incrementing sum if the condition is true
		}
	}

	// Closing the scanner after use
	sc.Close()

	// Returning the sum as the solution
	return sum
}

