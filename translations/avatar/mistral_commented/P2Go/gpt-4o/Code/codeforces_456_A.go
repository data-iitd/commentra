package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Print("Enter the number of tuples: ")
	fmt.Scan(&n)

	m := make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Printf("Enter tuple %d: ", i+1)
		fmt.Scan(&m[i][0], &m[i][1])
	}

	// Sort the slice in descending order based on the second element of the tuples
	sort.Slice(m, func(i, j int) bool {
		return m[i][1] > m[j][1]
	})

	a := m[0] // Initialize 'a' with the first tuple in the sorted list

	for _, i := range m[1:] {
		if i[1] > a[1] {
			fmt.Println("Happy Alex")
			return
		}
		a = i
	}

	fmt.Println("Poor Alex")
}

// <END-OF-CODE>
