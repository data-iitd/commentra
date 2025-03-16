
package main

import "fmt"

func solve(i, m int) bool {
	// Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
	if i > n {
		return false
	}

	// Base case: If length 'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
	if m < 0 {
		return false
	}

	// Base case: If length 'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to 'm', a subsequence of length 'm' can be formed starting from index 'i'
	if m == 0 || m-A[i+1] == 0 {
		flag = true // Setting the flag to true as a subsequence of length 'm' is found
		return true // Returning true to indicate that a subsequence of length 'm' is found
	}

	// Recursive case: If length 'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
	if !solve(i+1, m) {
		// Using the element at index 'i' to form the subsequence of length 'm'
		return solve(i+1, m-A[i])
	}

	return true
}

func main() {
	var n, q, M int
	fmt.Scan(&n)
	A := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		fmt.Scan(&M)
		flag = false
		solve(0, M)
		if flag {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

