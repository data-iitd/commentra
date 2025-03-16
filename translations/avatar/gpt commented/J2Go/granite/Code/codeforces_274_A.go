
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	n, _ := strconv.Atoi(read(reader))

	// Read the value of k
	k, _ := strconv.ParseInt(read(reader), 10, 64)

	// Initialize an array to hold the input numbers
	arr := make([]int64, n)

	// Create a map to store unique elements that meet the criteria
	set := make(map[int64]bool)

	// Read n integers into the array
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.ParseInt(read(reader), 10, 64)
	}

	// Sort the array to facilitate the processing of elements
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	// Initialize a counter to keep track of valid elements
	count := 0

	// Iterate through the sorted array to apply the conditions
	for i := 0; i < n; i++ {
		// Check if the current element is not divisible by k
		if arr[i]%k!= 0 {
			count++ // Increment count for valid element
			set[arr[i]] = true // Add the element to the set
		}
		// Check if the current element is divisible by k and its corresponding k-factor is not in the set
		else if!set[arr[i]/k] {
			count++ // Increment count for valid element
			set[arr[i]] = true // Add the element to the set
		}
	}

	// Output the final count of valid elements
	fmt.Println(count)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimSpace(string(str))
}

