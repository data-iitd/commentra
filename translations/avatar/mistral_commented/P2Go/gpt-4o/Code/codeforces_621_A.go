package main

import (
	"fmt"
	"sort"
)

func main() {
	// Take an integer 'n' as input
	var n int
	fmt.Scan(&n)

	// Create a slice 'lst' of 'n' integers taken as input
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lst[i])
	}

	// Sort the slice 'lst' in ascending order
	sort.Ints(lst)

	// Reverse the sorted slice 'lst'
	for i, j := 0, len(lst)-1; i < j; i, j = i+1, j-1 {
		lst[i], lst[j] = lst[j], lst[i]
	}

	// Initialize odd_digits counter 'od' to 0
	od := 0

	// Iterate through each integer 'i' in the slice 'lst'
	for _, i := range lst {
		// If the integer 'i' is odd, increment 'od' counter
		if i%2 != 0 {
			od++
		}
	}

	// Initialize sum and ok variables
	sum := 0
	ok := false

	// Iterate through each index 'i' in the range of 'n'
	for i := 0; i < n; i++ {
		// If the integer at index 'i' in the slice 'lst' is even, add it to the sum 'sum'
		if lst[i]%2 == 0 {
			sum += lst[i]
		} else {
			// If the integer at index 'i' in the slice 'lst' is odd and either 'ok' is true or 'od' is greater than 1
			if ok || od > 1 {
				sum += lst[i]
				od--
				ok = !ok
			}
		}
	}

	// Print the final sum
	fmt.Println(sum)
}

// <END-OF-CODE>
