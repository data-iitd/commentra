package main

import (
	"fmt"
	"sort"
)

func main() {
	var x [3]int
	max := 0

	// Reading the size of the array x from the standard input
	for i := 0; i < 3; i++ {
		fmt.Scan(&x[i])
		if x[i] > max {
			max = x[i]
		}
	}

	var k int
	fmt.Scan(&k)

	a := make([][]int64, 3)

	// Reading the elements of each sub-list a[i] of size x[i] from the standard input and sorting it in ascending order
	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
		for j := 0; j < x[i]; j++ {
			fmt.Scan(&a[i][j])
		}
		sort.Slice(a[i], func(p, q int) bool {
			return a[i][p] < a[i][q]
		})
	}

	ans := []int64{} // Declaring and initializing an empty slice ans to store the sum of three elements from different sub-lists that are less than or equal to k

	// Finding all such sums and adding them to the slice ans
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k { // Checking if the product of (i+1), (j+1), and (m+1) is less than or equal to k
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1] // Getting the elements of the sub-lists
					ans = append(ans, tmp) // Adding the sum of the three elements to the slice ans
				}
			}
		}
	}

	sort.Slice(ans, func(p, q int) bool {
		return ans[p] < ans[q]
	}) // Sorting the slice ans in ascending order

	n := len(ans) // Getting the size of the slice ans

	// Printing the i-th element of the slice ans, where i is the index of the element to be printed, starting from the last one
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

// <END-OF-CODE>
