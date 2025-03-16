
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = make([]int, 2)
		fmt.Scan(&m[i][0], &m[i][1])
	}
	m = sort(m)
	a := m[0]
	for i := 1; i < n; i++ {
		if m[i][1] > a[1] {
			fmt.Println("Happy Alex")
			break
		}
		a = m[i]
	}
	if i == n {
		fmt.Println("Poor Alex")
	}
}

func sort(m [][]int) [][]int {
	for i := 0; i < len(m); i++ {
		for j := i + 1; j < len(m); j++ {
			if m[i][1] < m[j][1] {
				m[i], m[j] = m[j], m[i]
			}
		}
	}
	return m
}

