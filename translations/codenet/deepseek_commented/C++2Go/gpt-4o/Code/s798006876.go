package main

import (
	"fmt"
)

const MAX_N = 1000 // Define the maximum size of the array

func main() {
	var m, nmi, nma int
	data := make([]int, MAX_N) // Declare the slice to store the data

	for {
		fmt.Scan(&m, &nmi, &nma) // Read the values of m, nmi, and nma
		if nmi == 0 {
			break // Exit the loop if nmi is 0
		}
		for i := 0; i < m; i++ {
			fmt.Scan(&data[i]) // Read m integers into the slice data
		}
		ma := 0 // Initialize the maximum difference to 0
		ans := 0 // Initialize the answer index to 0
		for i := nmi - 1; i < nma-1; i++ { // Loop through the range from nmi-1 to nma-2
			if ma <= data[i]-data[i+1] { // Check if the current difference is greater than the maximum difference found so far
				ans = i + 1 // Update the answer index
				ma = data[i] - data[i+1] // Update the maximum difference
			}
		}
		fmt.Println(ans) // Print the answer index
	}
}

// <END-OF-CODE>
