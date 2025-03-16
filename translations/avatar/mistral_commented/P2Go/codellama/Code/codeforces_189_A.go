package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func cutRibbon() {
	// Function to find the maximum number of pieces that can be cut from a ribbon of given length

	// Take input as a list of integers, where the first integer represents the length of the ribbon
	arr := strings.Split(input(), " ")

	// Assign the length of the ribbon to a variable
	length, _ := strconv.Atoi(arr[0])

	// Sort the next three elements of the list in ascending order
	arr = arr[1:4]
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	// Check if the length of the ribbon is divisible by the first element of the sorted list
	if length%arr[0] == 0 {
		// If it is, print the number of pieces required and return
		fmt.Println(length / arr[0])
		return
	}

	// Initialize an answer variable to keep track of the maximum number of pieces that can be cut
	ans := 0

	// If the first two elements of the sorted list are equal
	if arr[0] == arr[1] {
		// Initialize a variable k to keep track of the number of pieces required
		k := 0

		// Loop to find the maximum number of pieces that can be cut from the ribbon
		for i := 0; i <= length/arr[2]; i++ {
			// Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				// If it is, update the answer and k
				k = check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		// Initialize a variable k to keep track of the number of pieces required
		k := 0

		// Double loop to find the maximum number of pieces that can be cut from the ribbon
		for i := 0; i <= length/arr[2]; i++ {
			for j := 0; j <= length/arr[1]; j++ {
				// Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					// If it is, update the answer and k
					k = check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}

	// Print the final answer and return
	fmt.Println(ans)
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

func main() {
	cutRibbon()
}

