package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the values of n and k from input

	var s string
	fmt.Scan(&s) // Read the string s from input

	count := make([]int, 26) // Initialize a slice `count` with 26 zeros to count occurrences of each letter

	for _, c := range s {
		count[c-'A']++ // Increment the corresponding count for each character
	}

	sort.Sort(sort.Reverse(sort.IntSlice(count))) // Sort the `count` slice in descending order

	res := 0 // Initialize `res` to 0, which will be used to store the result

	for i := 0; i < 26; i++ {
		if count[i] >= k {
			res += k * k
			fmt.Println(res) // Print the result and exit the program
			return
		}
		k -= count[i]
		res += count[i] * count[i] // Add the square of the current count to `res`
	}

	fmt.Println(res) // Print the final result `res`
}

// <END-OF-CODE>
