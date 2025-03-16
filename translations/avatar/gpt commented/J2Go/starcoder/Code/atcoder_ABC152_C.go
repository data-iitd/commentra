package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	// Read the number of elements in the array
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the elements of the array")
	// Initialize an array to hold the input values
	arr := make([]int, N)
	// Populate the array with user input
	for i := 0; i < N; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	// Initialize a variable to keep track of the count of elements
	sum := 0
	// Create a priority queue to manage the elements
	q := make([]int, 0)
	// Iterate through the array to process each element
	for i := 0; i < N; i++ {
		// Add the current element to the priority queue
		q = append(q, arr[i])
		// Check if the current element is less than or equal to the smallest element in the queue
		if arr[i] <= q[0] {
			// Increment the count if the condition is met
			sum++
		}
	}
	// Return the final count of elements that met the condition
	fmt.Println(sum)
}

