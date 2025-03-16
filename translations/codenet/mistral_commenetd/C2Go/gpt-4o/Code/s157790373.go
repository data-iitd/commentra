package main

import (
	"fmt"
)

const LEN = 300
const TRUE = 1
const FALSE = -1

var n int
var A [LEN]int
var flag int

func solve(i int, m int) int {
	// Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
	if i > n {
		return FALSE
	}

	// Base case: If length 'm' is negative, return false
	if m < 0 {
		return FALSE
	}

	// Base case: If length 'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
	if m == 0 {
		flag = TRUE // Setting the flag to true as a subsequence of length 'm' is found
		return TRUE // Returning true to indicate that a subsequence of length 'm' is found
	}

	// Recursive case: If length 'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
	solve(i+1, m) // Not using the element at index 'i' to form the subsequence of length 'm'
	solve(i+1, m-A[i]) // Using the element at index 'i' to form the subsequence of length 'm'

	return flag
}

func main() {
	var q, M int // 'q' is the number of queries and 'M' is the length of subsequence to be checked in each query

	fmt.Scan(&n) // Reading the size of the array 'A'
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i]) // Reading the elements of the array 'A'
	}

	fmt.Scan(&q) // Reading the number of queries
	for i := 0; i < q; i++ { // Loop through all the queries
		fmt.Scan(&M) // Reading the length of subsequence to be checked in the current query
		flag = FALSE // Initializing the flag to false

		solve(0, M) // Calling the function 'solve' to check if there is a subsequence of given length 'M' in the array 'A'

		if flag == TRUE {
			fmt.Println("yes") // If a subsequence of given length 'M' is found, print 'yes'
		} else {
			fmt.Println("no") // If no subsequence of given length 'M' is found, print 'no'
		}
	}
}

// <END-OF-CODE>
