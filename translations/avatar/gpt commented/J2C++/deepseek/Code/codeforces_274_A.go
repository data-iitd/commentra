package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Read the value of k
	scanner.Scan()
	var k int64
	fmt.Sscan(scanner.Text(), &k)
	
	// Initialize an array to hold the input numbers
	arr := make([]int64, n)
	
	// Create a map to store unique elements that meet the criteria
	set := make(map[int64]bool)
	
	// Read n long integers into the array
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr[i])
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
		if arr[i] % k != 0 {
			if _, exists := set[arr[i]]; !exists {
				count++ // Increment count for valid element
				set[arr[i]] = true // Add the element to the set
			}
		} else if arr[i] / k != arr[i] { // Check if the current element is divisible by k and its corresponding k-factor is not in the set
			if _, exists := set[arr[i] / k]; !exists {
				count++ // Increment count for valid element
				set[arr[i]] = true // Add the element to the set
			}
		}
	}
	
	// Output the final count of valid elements
	fmt.Println(count)
}
