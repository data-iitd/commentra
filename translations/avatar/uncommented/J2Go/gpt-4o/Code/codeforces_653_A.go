package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, 0, n)
	for i := 0; i < n; i++ {
		var value int
		fmt.Scan(&value)
		a = append(a, value)
	}

	// Remove duplicates
	uniqueMap := make(map[int]struct{})
	for _, value := range a {
		uniqueMap[value] = struct{}{}
	}

	// Convert map keys to slice
	uniqueSlice := make([]int, 0, len(uniqueMap))
	for key := range uniqueMap {
		uniqueSlice = append(uniqueSlice, key)
	}

	// Sort the slice
	sort.Ints(uniqueSlice)

	found := false
	for i := 0; i < len(uniqueSlice)-2; i++ {
		if uniqueSlice[i]+1 == uniqueSlice[i+1] && uniqueSlice[i+1]+1 == uniqueSlice[i+2] {
			found = true
			break
		}
	}

	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
