package main

import "fmt"

func main() {
	var N, ans, i, count int
	fmt.Scan(&N)
	A := make([]int, N)
	for i = 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	i = 0
	ans = 0
	count = 0
	for i < N-1 {
		if A[i] == A[i+1] {
			count++
			if count%2 != 0 {
				ans++
			}
		} else {
			count = 0
		}
		i++
	}
	fmt.Println(ans)
}

