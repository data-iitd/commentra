package main

import "fmt"

func search(A []int, n int, key int) bool {
	A[n] = key
	i := 0
	for A[i]!= key {
		i++
	}
	return i!= n
}

func main() {
	var n, q, key, sum int
	var A []int
	fmt.Scanf("%d", &n)
	A = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}
	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &key)
		if search(A, n, key) {
			sum++
		}
	}
	fmt.Printf("%d\n", sum)
}

