package main

import "fmt"

func linearsearch(S []int, n int, key int) int {
	i := 0
	count := 0
	for i < n {
		if S[i] == key {
			count = 1
			return count
		}
		i++
	}
	return count
}

func main() {
	var i, j, n, q, S [10000]int
	var T [10000]int
	var count, key int
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
		if linearsearch(S[:n], n, key) == 0 {
			count++
		}
	}
	fmt.Printf("%d\n", count)
}

