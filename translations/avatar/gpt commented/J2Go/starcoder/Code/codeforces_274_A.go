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
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	// Read the number of elements in the array
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the value of k")
	// Read the value of k
	k, _ := strconv.Atoi(reader.ReadString('\n'))
	// Initialize an array to hold the input numbers
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	// Read n long integers into the array
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	// Sort the array to facilitate the processing of elements
	sort.Ints(arr)
	// Initialize a counter to keep track of valid elements
	count := 0
	// Iterate through the sorted array to apply the conditions
	for i := 0; i < n; i++ {
		// Check if the current element is not divisible by k
		if arr[i]%k!= 0 {
			count++ // Increment count for valid element
		}
		// Check if the current element is divisible by k and its corresponding k-factor is not in the set
		if arr[i]%k == 0 && arr[i]/k!= 0 && arr[i]/k!= arr[i] {
			count++ // Increment count for valid element
		}
	}
	// Output the final count of valid elements
	fmt.Println(count)
}

