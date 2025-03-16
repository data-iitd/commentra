package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func s() string {
	var n int
	fmt.Scan(&n) // Read the number of elements
	var a []int
	input, _ := fmt.Scanln() // Read the line of integers
	for _, str := range strings.Fields(input) {
		num, _ := strconv.Atoi(str)
		a = append(a, num)
	}
	sort.Ints(a) // Sort the slice

	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			return "YES"
		}
	}
	return "NO"
}

func main() {
	fmt.Println(s())
}

// <END-OF-CODE>
