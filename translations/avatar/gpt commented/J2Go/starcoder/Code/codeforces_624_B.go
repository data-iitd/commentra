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
	// Read the number of elements from the user
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	// Initialize an array to hold the Long integers
	ans := make([]int, n)
	// Read n Long integers from the user and store them in the array
	for i := 0; i < n; i++ {
		ans[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	// Sort the array in ascending order
	sort.Ints(ans)
	// Initialize count with the largest element in the sorted array
	count := ans[n-1]
	// Iterate through the array from the second largest element to the first
	for i := n - 2; i >= 0; i-- {
		// If the current element is less than the next element, add it to count
		if ans[i] < ans[i+1] {
			count += ans[i]
		} else {
			// If the current element is not less, decrement it until it is less than the next element
			for ans[i] >= ans[i+1] {
				ans[i]--
			}
			// If the decremented value is still positive, add it to count
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}
	// Print the final count
	fmt.Println(count)
}

