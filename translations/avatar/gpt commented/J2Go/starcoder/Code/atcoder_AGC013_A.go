package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize an array to store the input integers
	A := make([]int, N)

	// Read N integers from the user and store them in the array
	for i := 0; i < N; i++ {
		fmt.Printf("Enter the %d element: ", i + 1)
		input, _ := reader.ReadString('\n')
		A[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Initialize a counter to keep track of the number of segments
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
			for {
				i++ // Move to the next element
				// Break if we reach the end of the array
				if i == N - 1 {
					break
				}
				// Break if the current element is no longer less than the next element
				if A[i] > A[i + 1] {
					break
				}
			}
			// Increment the count for the found segment
			count++
		}
		// If the current element is greater than the next element, find the end of the decreasing segment
		else {
			for {
				i++ // Move to the next element
				// Break if we reach the end of the array
				if i == N - 1 {
					break
				}
				// Break if the current element is no longer greater than the next element
				if A[i] < A[i + 1] {
					break
				}
			}
			// Increment the count for the found segment
			count++
		}
	}

	// Output the total number of segments found
	fmt.Printf("The total number of segments found is %d\n", count)
}

