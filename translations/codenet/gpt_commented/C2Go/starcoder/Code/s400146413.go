package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// linearsearch performs a linear search on an array
func linearsearch(S []int, n int, key int) int {
	i := 0
	count := 0
	for {
		if S[i] == key {
			count = 1
			return count
		}
		i++
		if i >= n {
			count = 1
			return count
		}
	}
}

func main() {
	var i, j, n, q, key int
	var S []int
	var T []int
	var count int
	S = make([]int, 10000)
	T = make([]int, 10000)
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &S[i])
	}
	fmt.Scanf("%d", &q)
	for j = 0; j < q; j++ {
		fmt.Scanf("%d", &T[j])
	}
	for j = 0; j < q; j++ {
		key = T[j]
		if linearsearch(S, n, key) == 0 {
			count++
		}
	}
	fmt.Printf("%d\n", count)
}

