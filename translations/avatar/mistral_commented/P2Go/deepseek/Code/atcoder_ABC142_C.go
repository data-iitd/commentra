package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	var A [][]int
	input := ""
	fmt.Scan(&input)
	values := strings.Split(input, " ")

	for i, x := range values {
		val, _ := strconv.Atoi(x)
		A = append(A, []int{i + 1, val})
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	var A__ []int
	for _, a := range A {
		A__ = append(A__, a[0])
	}

	for i := 0; i < len(A__); i++ {
		if i < len(A__) - 1 {
			fmt.Print(A__[i], " ")
		} else {
			fmt.Print(A__[i])
		}
	}
	fmt.Println()
}

