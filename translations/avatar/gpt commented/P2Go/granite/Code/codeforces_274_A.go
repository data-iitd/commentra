
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers from input: num (number of elements) and k (the divisor)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	split := strings.Split(input, " ")
	num, _ := strconv.Atoi(split[0])
	k, _ := strconv.Atoi(split[1])

	// Read the array of integers from input
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	split = strings.Split(input, " ")
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		arr[i], _ = strconv.Atoi(split[i])
	}

	// Initialize a set to keep track of unique elements that meet the criteria
	different := make(map[int]bool)

	// Initialize a variable to keep track of the maximum size of the 'different' set
	temp := 0

	// Sort the array to process elements in ascending order
	for i := 0; i < num; i++ {
		for j := i + 1; j < num; j++ {
			if arr[i] > arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}

	// Iterate through each element in the sorted array
	for _, x := range arr {
		// Check if the element is not divisible by k or if its quotient is not already in the 'different' set
		if (x%k!= 0 ||!different[x/k]) {
			// Add the element to the 'different' set since it meets the criteria
			different[x] = true
		}

		// Update the maximum size of the 'different' set if the current size is larger
		temp = max(len(different), temp)
	}

	// Print the maximum size of the 'different' set found
	fmt.Println(temp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

