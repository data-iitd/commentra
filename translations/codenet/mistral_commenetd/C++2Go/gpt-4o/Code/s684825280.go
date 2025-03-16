package main

import (
	"fmt"
	"sort"
)

const SIZE = int(1e5*2) + 13 // Define the size of the slice

func main() {
	var n, k int // Declare two integers 'n' and 'k' to read input
	fmt.Scan(&n, &k) // Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

	cnt := make([]int, SIZE) // Initialize a slice 'cnt' of size 'SIZE' to store the frequency count of each element

	for i := 0; i < n; i++ { // Loop through the input elements
		var x int // Declare an integer 'x' to read an element from the standard input
		fmt.Scan(&x) // Read an element 'x' from the standard input
		cnt[x]++ // Increment the frequency count of the element 'x' in the slice 'cnt'
	}

	var a []int // Initialize an empty slice 'a' to store the frequency count of each element

	for i := 0; i < len(cnt); i++ { // Loop through all elements in the slice 'cnt'
		if cnt[i] > 0 { // If the frequency count of an element is greater than zero
			a = append(a, cnt[i]) // Add the frequency count to the slice 'a'
		}
	}

	sort.Ints(a) // Sort the slice 'a' in ascending order

	ans := 0 // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts
	m := len(a) - k // Calculate the index of the last frequency count to be considered

	for i := 0; i < m; i++ { // Loop through the first 'm' frequency counts and add them to the variable 'ans'
		ans += a[i]
	}

	fmt.Println(ans) // Print the result 'ans' to the standard output
}

// <END-OF-CODE>
