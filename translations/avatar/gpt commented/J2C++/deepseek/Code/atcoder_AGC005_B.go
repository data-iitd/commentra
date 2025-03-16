package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	N := 0
	fmt.Sscan(scanner.Text(), &N)
	
	// Initialize an array to hold the input values
	a := make([]int, N)
	
	// Populate the array with input values
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
	}
	
	// Arrays to hold the counts of elements to the left and right of each element
	leftl := make([]int, N)
	rightl := make([]int, N)
	
	// Slice to help with calculating the left and right counts
	que := []int{}
	
	// Calculate the right counts for each element
	index := 0
	for index < N {
		// While the slice is not empty and the current element is smaller than the element at the index at the front of the slice
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Pop the index from the slice and calculate the right count
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			rightl[ind] = index - ind - 1
		}
		// Push the current index onto the slice
		que = append(que, index)
		index++
	}
	
	// For any remaining indices in the slice, calculate the right counts
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		rightl[ind] = N - ind - 1
	}
	
	// Reset index to calculate left counts
	index = N - 1
	
	// Calculate the left counts for each element
	for index >= 0 {
		// While the slice is not empty and the current element is smaller than the element at the index at the front of the slice
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			// Pop the index from the slice and calculate the left count
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			leftl[ind] = ind - index - 1
		}
		// Push the current index onto the slice
		que = append(que, index)
		index--
	}
	
	// For any remaining indices in the slice, calculate the left counts
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		leftl[ind] = ind - index - 1
	}
	
	// Calculate the final answer based on the left and right counts
	var ans int64 = 0
	for i := 0; i < N; i++ {
		// For each element, multiply its value by the number of valid subarrays it can form
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}
	
	// Output the final result
	fmt.Println(ans)
}
