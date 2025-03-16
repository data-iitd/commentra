
package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read two integers `n` and `k` from the standard input, separated by a space
	n, k := readInts()

	// Create a list of integers from the standard input, each line containing `n` integers
	numbers := readInts()

	// Sort the list in ascending order
	sort.Ints(numbers)

	// Calculate the sum of the first `k` elements of the sorted list
	result := sum(numbers[:k])

	// Print the result
	fmt.Println(result)
}

func readInts() (int, int) {
	// Read two integers `n` and `k` from the standard input, separated by a space
	var n, k int
	fmt.Scan(&n, &k)
	return n, k
}

func readInts() []int {
	// Create a list of integers from the standard input, each line containing `n` integers
	var numbers []int
	for i := 0; i < n; i++ {
		var number int
		fmt.Scan(&number)
		numbers = append(numbers, number)
	}
	return numbers
}

func sum(numbers []int) int {
	// Calculate the sum of the first `k` elements of the sorted list
	var result int
	for i := 0; i < k; i++ {
		result += numbers[i]
	}
	return result
}

