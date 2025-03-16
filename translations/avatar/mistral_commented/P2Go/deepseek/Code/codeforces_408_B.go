package main

import (
	"bufio"
	"container/counter"
	"fmt"
	"math"
	"os"
)

// Define helper functions
func hpop(heap []int) int {
	heap[0], heap[len(heap)-1] = heap[len(heap)-1], heap[0]
	heap = heap[:len(heap)-1]
	return heap
}

func hpush(heap []int, item int) []int {
	heap = append(heap, item)
	return heap
}

// Function to find the solution
func solution() {
	// Read the first line and count the number of occurrences of each color
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	counter := counter.New()
	for _, color := range line {
		counter.Add(string(color))
	}

	// Read the second line and count the number of occurrences of each color
	line, _ = reader.ReadString('\n')
	madeCounter := counter.New()
	for _, color := range line {
		madeCounter.Add(string(color))
	}

	// Initialize result to 0
	res := 0

	// Iterate through each color in madeCounter
	for color := range madeCounter {
		// Check if the color is present in counter
		if !counter.Contains(color) {
			// If not, print -1 and exit the function
			fmt.Println(-1)
			return
		}

		// Update the result by adding the minimum of counter and made counts
		res += int(math.Min(float64(counter.Get(color)), float64(madeCounter.Get(color))))
	}

	// Print the result
	fmt.Println(res)
}

// Main function to run the solution function for multiple test cases
func main() {
	// Read the number of test cases
	reader := bufio.NewReader(os.Stdin)
	t, _ := reader.ReadString('\n')
	tInt := int(t)

	// Run the solution function for each test case
	for i := 0; i < tInt; i++ {
		solution()
	}
}

