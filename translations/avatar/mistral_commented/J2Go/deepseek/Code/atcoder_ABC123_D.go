package main

import (
	"fmt"
	"sort"
)

func main() {
	var x [3]int
	var max int

	// Reading the size of the array x from the standard input stream
	for i := 0; i < 3; i++ {
		fmt.Scan(&x[i])
		if x[i] > max {
			max = x[i]
		}
	}

	var k int
	fmt.Scan(&k)

	var a [3][]int64

	// Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
		for j := 0; j < x[i]; j++ {
			fmt.Scan(&a[i][j])
		}
		sort.Slice(a[i], func(p, q int) bool {
			return a[i][p] < a[i][q]
		})
	}

	var ans []int64

	// Finding all such sums and adding them to the list ans
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}

	sort.Slice(ans, func(p, q int) bool {
		return ans[p] < ans[q]
	})

	n := len(ans)

	// Printing the i-th element of the list ans, where i is the index of the element to be printed, starting from the last one
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

