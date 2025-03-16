
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var N int64
	fmt.Fscanf(reader, "%d\n", &N)
	T := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Fscanf(reader, "%d", &T[i])
	}
	var M int64
	fmt.Fscanf(reader, "%d\n", &M)
	P := make([]int64, M)
	X := make([]int64, M)
	for i := int64(0); i < M; i++ {
		fmt.Fscanf(reader, "%d %d\n", &P[i], &X[i])
	}
	solve(N, T, M, P, X)
}

func solve(N int64, T []int64, M int64, P []int64, X []int64) {
	for i := int64(0); i < M; i++ {
		ans := int64(0)
		for j := int64(0); j < N; j++ {
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		fmt.Println(ans)
	}
}

