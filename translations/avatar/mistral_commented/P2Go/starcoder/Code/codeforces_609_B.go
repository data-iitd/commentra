
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input as a list of integers
func readInput() []int {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	var lst []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		lst = append(lst, x)
	}
	return lst
}

func main() {
	// Read input as a list of integers
	lst := readInput()

	// Initialize an empty map 'l' to store the frequency of each element
	l := make(map[int]int)

	// Iterate through each element in the list 'lst'
	for _, x := range lst {
		// If the current element is not already present in the map 'l'
		if _, ok := l[x];!ok {
			// Add the current element to the map 'l' with a frequency of 1
			l[x] = 1
		} else {
			// Increment the frequency of the current element in the map 'l'
			l[x] += 1
		}
	}

	// Initialize result variable'res' to 0
	res := 0

	// Iterate through each element in the list 'lst'
	for _, x := range lst {
		// If the frequency of the current element in the map 'l' is greater than 1
		if l[x] > 1 {
			// Calculate the number of elements that have a smaller frequency than the current element
			// and add it to the result variable'res'
			res += len(lst) - strings.Count(fmt.Sprint(lst), fmt.Sprint(x)) - l[x]
			// Decrease the frequency of the current element in the map 'l' by 1
			l[x] -= 1
		} else {
			// Calculate the number of elements that have not been processed yet and add it to the result variable'res'
			res += len(lst) - strings.Count(fmt.Sprint(lst), fmt.Sprint(x)) - 1
	}

	// Print the final result
	fmt.Println(res)
}

