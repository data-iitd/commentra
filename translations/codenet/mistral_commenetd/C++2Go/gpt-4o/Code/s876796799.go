package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	a := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	usedInds := make([]int, 0) // Slice to keep track of used indices
	ans := int64(0)            // Initialize answer variable 'ans' to 0

	for i := 0; i < N; i++ {
		curInd := a[i] // Current element

		// Find left border
		leftBorder := int64(-1)
		if len(usedInds) > 0 {
			leftIdx := sort.Search(len(usedInds), func(j int) bool {
				return int64(usedInds[j]) >= curInd
			})

			if leftIdx > 0 {
				leftBorder = int64(usedInds[leftIdx-1])
			}
		}

		// Find right border
		rightBorder := int64(N)
		if len(usedInds) > 0 {
			rightIdx := sort.Search(len(usedInds), func(j int) bool {
				return int64(usedInds[j]) > curInd
			})
			if rightIdx < len(usedInds) {
				rightBorder = int64(usedInds[rightIdx])
			}
		}

		// Calculate contribution to the answer
		ans += (curInd - leftBorder) * (rightBorder - curInd) * int64(i+1)

		// Insert current index into used indices
		usedInds = append(usedInds, int(curInd))
		sort.Ints(usedInds) // Keep the slice sorted
	}

	// Print the final answer 'ans'
	fmt.Println(ans)
}

// <END-OF-CODE>
