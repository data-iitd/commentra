
package main

import (
	"fmt"
	"math"
)

func main() {
	// Define a constant for array or list size
	const NUM = int(math.Pow(10, 5) + 2)

	// Initialize a Scanner object to read input
	sc := make([]int, NUM)

	// Read the number of elements
	N := sc[0]

	// Initialize a HashMap to store value and its index
	map := make(map[int]int)

	// Initialize a PriorityQueue to store numbers
	nums := make([]int, NUM)

	// Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
	for i := 0; i < N; i++ {
		tmp := sc[i+1]
		nums[i] = tmp
		map[tmp] = i
	}

	// Initialize variables to keep track of the current index and the count of differences
	bin := 0
	diff := 0

	// Loop until the PriorityQueue is empty
	for len(nums) > 0 {
		// Retrieve the next number and its index from the PriorityQueue and HashMap
		num := nums[0]
		idx := map[num]

		// If the current index is not even when bin is even (or vice versa), increment the diff counter
		if (bin%2) != (idx%2) {
			diff++
		}

		// Update bin and take modulo 2 to keep it within 0 or 1
		bin++
		bin %= 2

		// Remove the number from the PriorityQueue
		nums = nums[1:]
	}

	// Calculate the answer by dividing diff by 2
	ans := diff / 2

	// Print the result
	fmt.Println(ans)
}

