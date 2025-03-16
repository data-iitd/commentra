package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Print("Enter the number of tuples: ")
	fmt.Scan(&n)

	m := make([][]int, n)
	for i := 0; i < n; i++ {
		fmt.Printf("Enter tuple %d: ", i+1)
		var a, b int
		fmt.Scan(&a, &b)
		m[i] = []int{a, b}
	}

	sort.Slice(m, func(i, j int) bool {
		return m[i][0] > m[j][0]
	})

	a := m[0]
	for _, i := range m[1:] {
		if i[1] > a[1] {
			fmt.Println("Happy Alex")
			return
		}
		a = i
	}
	fmt.Println("Poor Alex")
}

