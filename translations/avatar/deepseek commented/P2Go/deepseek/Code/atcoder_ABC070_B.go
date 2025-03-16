package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	A := []int{}
	for _, numStr := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(numStr)
		A = append(A, num)
	}

	if A[1] <= A[2] || A[3] <= A[0] {
		fmt.Println(0)
	} else {
		sort.Ints(A)
		fmt.Println(A[2] - A[1])
	}
}

