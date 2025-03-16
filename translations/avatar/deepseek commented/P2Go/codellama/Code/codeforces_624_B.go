
package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	// Step 1: Reading the number of elements (n)
	var n int
	fmt.Scan(&n)

	// Step 2: Reading the list of elements (a)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Step 3: Initializing variables
	pre := math.MaxInt32
	ans := 0

	// Step 4: Sorting the list in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	// Step 5: Iterating through the list
	for j := 0; j < n; j++ {
		// Calculate the maximum value that can be added to ans
		ans += int(math.Max(0, math.Min(float64(pre-1), float64(a[j]))))
		// Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
		pre = int(math.Max(0, math.Min(float64(pre-1), float64(a[j]))))
	}

	// Step 6: Printing the result
	fmt.Println(ans)
}

