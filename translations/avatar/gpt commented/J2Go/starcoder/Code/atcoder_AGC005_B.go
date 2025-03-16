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
	// Read the number of elements in the array
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	// Initialize an array to hold the input values
	a := make([]int, N)
	// Populate the array with input values
	for i := 0; i < N; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	// Arrays to hold the counts of elements to the left and right of each element
	leftl := make([]int, N)
	rightl := make([]int, N)
	// Deque to help with calculating the left and right counts
	que := make([]int, 0)
	// Calculate the right counts for each element
	index := 0
	for index < N {
		// While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Pop the index from the deque and calculate the right count
			ind := que[len(que)-1]
			rightl[ind] = index - ind - 1
			que = que[:len(que)-1]
		}
		// Push the current index onto the deque
		que = append(que, index)
		index++
	}
	// For any remaining indices in the deque, calculate the right counts
	for len(que) > 0 {
		ind := que[len(que)-1]
		rightl[ind] = N - ind - 1
		que = que[:len(que)-1]
	}
	// Reset index to calculate left counts
	index = N - 1
	// Calculate the left counts for each element
	for index >= 0 {
		// While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Pop the index from the deque and calculate the left count
			ind := que[len(que)-1]
			leftl[ind] = ind - index - 1
			que = que[:len(que)-1]
		}
		// Push the current index onto the deque
		que = append(que, index)
		index--
	}
	// For any remaining indices in the deque, calculate the left counts
	for len(que) > 0 {
		ind := que[len(que)-1]
		leftl[ind] = ind - index - 1
		que = que[:len(que)-1]
	}
	// Calculate the final answer based on the left and right counts
	ans := 0
	for i := 0; i < N; i++ {
		// For each element, multiply its value by the number of valid subarrays it can form
		ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
	}
	// Output the final result
	fmt.Println(ans)
}

