package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the user
	stdIn := os.Stdin

	// Reading the number of elements N from user input
	N, _ := strconv.Atoi(ReadLine(stdIn))

	// Initializing an array A of size N to store the input integers
	A := make([]int, N)

	// Loop to read N integers from user input and store them in array A
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(ReadLine(stdIn))
	}

	// Initializing a counter to keep track of the number of segments
	count := 0

	// Loop through the array to identify segments of increasing or decreasing values
	for i := 0; i < N; i++ {
		// If we are at the last element, increment the count
		if i == N-1 {
			count++
		}
		// If the current element is equal to the next element, do nothing
		else if A[i] == A[i+1] {
			// No action needed, just continue
		}
		// If the current element is less than the next element, find the end of the increasing segment
		else if A[i] < A[i+1] {
			for ; i < N-1 && A[i] <= A[i+1]; i++ {
				// No action needed, just continue
			}
			// Increment the count for the found segment
			count++
		}
		// If the current element is greater than the next element, find the end of the decreasing segment
		else {
			for ; i < N-1 && A[i] >= A[i+1]; i++ {
				// No action needed, just continue
			}
			// Increment the count for the found segment
			count++
		}
	}

	// Output the total number of segments found
	fmt.Println(count)
}

func ReadLine(reader *os.File) string {
	buf := make([]byte, 0, 16)
	for {
		line, isPrefix, err := reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}

