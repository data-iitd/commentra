package main

import (
	"fmt"
	"sort"
)

var l []int64
const limit int64 = 10000000000

// Recursive function to generate numbers composed of 4s and 7s
func gen(number int64, four int, seven int) {
	// Base case: if the generated number exceeds the limit, stop recursion
	if number > limit {
		return
	}
	// If the number is positive and the count of 4s equals the count of 7s, add it to the list
	if number > 0 && four == seven {
		l = append(l, number)
	}
	// Recursively generate the next number by adding a 4
	gen(number*10+4, four+1, seven)
	// Recursively generate the next number by adding a 7
	gen(number*10+7, four, seven+1)
}

// Main function to execute the number generation and find the answer
func main() {
	// Start the generation process with initial values
	gen(0, 0, 0)
	// Sort the list of generated numbers
	sort.Slice(l, func(i, j int) bool {
		return l[i] < l[j]
	})
	
	var n int64
	// Read an integer input from the user
	fmt.Scan(&n)
	var ans int64 = -1
	// Iterate through the sorted list to find the smallest number greater than or equal to n
	for _, val := range l {
		if val >= n {
			ans = val
			break
		}
	}
	// Print the result
	fmt.Println(ans)
}

// <END-OF-CODE>
