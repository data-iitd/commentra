package main

import (
	"fmt"
	"sort"
)

func main() {
	var array [10]int
	for i := 0; i < 10; i++ {
		fmt.Scan(&array[i])
	}

	sort.Slice(array[:], func(i, j int) bool {
		return array[j] < array[i]
	})

	for i := 0; i < 3; i++ {
		fmt.Println(array[i])
	}
}

// <END-OF-CODE>
