package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	first  int
	second string
}

func main() {
	var n int
	for {
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		var v [22]Pair // Array to store n pairs
		var d [33][]int // Array of slices to store indices

		for i := 0; i < 33; i++ {
			d[i] = []int{} // Clear all slices in d
		}

		for i := 0; i < n; i++ {
			v[i].first = 0 // Initialize the first element of v to 0
			var m int
			fmt.Scan(&v[i].second, &m) // Read the string and m
			for j := 0; j < m; j++ {
				var a int
				fmt.Scan(&a)
				v[i].first += n - len(d[a]) // Update the first element of v
				for _, k := range d[a] { // Update the first elements of other v elements
					v[k].first--
				}
				d[a] = append(d[a], i) // Store the index of the current element in d
			}
		}

		sort.Slice(v[:n], func(i, j int) bool {
			return v[i].first < v[j].first // Sort the array v based on the first element of Pair
		})

		fmt.Println(v[0].first, v[0].second) // Output the first element of v
	}
}

// <END-OF-CODE>
