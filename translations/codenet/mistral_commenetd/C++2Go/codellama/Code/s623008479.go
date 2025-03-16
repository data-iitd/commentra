package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int // Declare two integer variables, n and k, to read the number of elements and the size of the subarray from the user

	fmt.Scan(&n, &k) // Read the number of elements and the size of the subarray from the user and store them in the variables n and k

	l := make([]int, n) // Declare a vector l of size n and initialize it with n default-constructed elements

	for i := 0; i < n; i++ { // Iterate through the elements of the vector l and read each element from the user
		fmt.Scan(&l[i])
	}

	sort.Ints(l) // Sort the vector l in ascending order

	ans := 0 // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

	for i := 0; i < k; i++ { // Iterate through the first k elements in descending order and add their values to the variable ans
		ans += l[n-1-i]
	}

	fmt.Println(ans) // Output the value of the variable ans to the console
}

