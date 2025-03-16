package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a Scanner object to read input from the user
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Reading the number of elements N from user input
	fmt.Fscan(reader, &N)
	
	// Initializing an array A of size N to store the input integers
	A := make([]int, N)
	
	// Loop to read N integers from user input and store them in array A
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	
	// Initializing a counter to keep track of the number of segments
	count := 0
	
	// Loop through the array to identify segments of increasing or decreasing values
	for i := 0; i < N; i++ {
		// If we are at the last element, increment the count
		if i == N - 1 {
			count++
		} 
		// If the current element is equal to the next element, do nothing
		else if A[i] == A[i + 1] {
			// No action needed, just continue
		} 
		// If the current element is less than the next element, find the end of the increasing segment
		else if A[i] < A[i + 1] {
			for A[i] <= A[i + 1] {
				i++ // Move to the next element
				// Break if we reach the end of the array
				if i == N - 1 {
					break
				}
			}
			// Increment the count for the found segment
			count++
		} 
		// If the current element is greater than the next element, find the end of the decreasing segment
		else {
			for A[i] >= A[i + 1] {
				i++ // Move to the next element
				// Break if we reach the end of the array
				if i == N - 1 {
					break
				}
			}
			// Increment the count for the found segment
			count++
		}
	}
	
	// Output the total number of segments found
	fmt.Fprintln(writer, count)
}
