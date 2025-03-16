<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to search for an element in an array
func linearSearch(arr []int, key int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == key {
			return i
		}
	}
	return -1
}

func main() {
	// Getting the size of the array
	size := 0
	fmt.Scanf("%d", &size)

	// Getting the array elements
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	// Getting the number of queries
	queries := 0
	fmt.Scanf("%d", &queries)

	// Getting the queries
	for i := 0; i < queries; i++ {
		query := 0
		fmt.Scanf("%d", &query)

		// Searching for the query in the array
		index := linearSearch(arr, query)

		// Printing the result
		if index!= -1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

