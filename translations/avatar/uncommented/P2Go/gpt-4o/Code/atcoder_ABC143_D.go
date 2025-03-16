package main

import (
	"fmt"
	"sort"
)

func bisectLeft(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool { return arr[i] >= x })
}

func bisectRight(arr []int, x int) int {
	return sort.Search(len(arr), func(i int) bool { return arr[i] > x })
}

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	sort.Ints(l)

	ans := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i]
			b := l[j]
			right := bisectLeft(l, a+b)
			left := bisectRight(l, max(a-b, b-a))
			tmp := max(0, right-left)
			if left <= i && i < right {
				tmp--
			}
			if left <= j && j < right {
				tmp--
			}
			ans += tmp
		}
	}
	fmt.Println(ans / 3)
}

// Helper function to get the maximum of two integers
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// <END-OF-CODE>
