package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Initialize scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of test cases
	scanner.Scan()
	t := scanner.Text()
	
	// Convert the number of test cases to an integer
	numTestCases := 0
	fmt.Sscanf(t, "%d", &numTestCases)
	
	// Initialize slices for max and min values
	maxHeap := []int{}
	minHeap := []int{}
	
	// Initialize variables to keep track of sums and the minimum value
	var sumMin, sumMax, sumb int64
	min := 0
	
	// Process each test case
	for i := 0; i < numTestCases; i++ {
		// Read the input for the current test case
		scanner.Scan()
		s := scanner.Text()
		parts := bufio.NewScanner(bufio.NewReader(os.Stdin))
		parts.Scan()
		scanner.Scan()
		in := 0
		fmt.Sscanf(scanner.Text(), "%d", &in)
		
		// If the command is '2', calculate and print the result
		if s[0] == '2' {
			ans := int64(min)
			ans *= int64(len(minHeap))
			ans -= sumMin
			ans1 := int64(min)
			ans1 *= int64(len(maxHeap))
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			// If the command is '1', add the new value to the appropriate heap
			parts.Scan()
			scanner.Scan()
			in := 0
			fmt.Sscanf(scanner.Text(), "%d", &in)
			sumb += int64(in)
			
			if in > min {
				maxHeap = append(maxHeap, in)
				sumMax += int64(in)
			} else {
				minHeap = append(minHeap, in)
				sumMin += int64(in)
			}
			
			// Balance the heaps
			if len(minHeap) > len(maxHeap) {
				sumMax += int64(minHeap[0])
				sumMin -= int64(minHeap[0])
				maxHeap = append(maxHeap, minHeap[0])
				minHeap = minHeap[1:]
			}
			
			if len(minHeap) < len(maxHeap) {
				sumMax -= int64(maxHeap[0])
				sumMin += int64(maxHeap[0])
				minHeap = append(minHeap, maxHeap[0])
				maxHeap = maxHeap[1:]
			}
			
			// Update the minimum value
			sort.Ints(minHeap)
			min = minHeap[0]
		}
	}
}
