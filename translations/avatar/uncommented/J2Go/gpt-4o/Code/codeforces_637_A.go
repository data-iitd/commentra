package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	ara := make([]int, n)
	mapCount := make(map[int]int)

	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		ara[i] = v
		mapCount[v]++
	}

	max := 0
	for _, count := range mapCount {
		if count > max {
			max = count
		}
	}

	mapOccurrence := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, exists := mapOccurrence[ara[i]]; !exists {
			mapOccurrence[ara[i]] = 1
		} else {
			mapOccurrence[ara[i]]++
		}

		if mapOccurrence[ara[i]] == max {
			fmt.Println(ara[i])
			break
		}
	}
}

// <END-OF-CODE>
