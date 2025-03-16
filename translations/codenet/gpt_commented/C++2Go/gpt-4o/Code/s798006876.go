package main

import (
	"fmt"
)

const MAX_N = 1000 // Define a constant for the maximum number of elements

func main() {
	var m, nmi, nma int
	data := make([]int, MAX_N) // Slice to hold input data

	// Read inputs m, nmi, and nma until nmi is not equal to 0
	for {
		fmt.Scan(&m, &nmi, &nma)
		if nmi == 0 {
			break
		}

		// Read m elements into the data slice
		for i := 0; i < m; i++ {
			fmt.Scan(&data[i])
		}

		// Initialize variables to track the maximum difference and the answer index
		ma := 0 // Maximum difference found
		ans := 0 // Index of the element that gives the maximum difference

		// Loop through the specified range from nmi-1 to nma-1
		for i := nmi - 1; i < nma-1; i++ {
			// Check if the current difference is greater than the maximum found so far
			if ma <= data[i]-data[i+1] {
				ans = i + 1 // Update the answer index
				ma = data[i] - data[i+1] // Update the maximum difference
			}
		}

		// Output the index of the element that produced the maximum difference
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
