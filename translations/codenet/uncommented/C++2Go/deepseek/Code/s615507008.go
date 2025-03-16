package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(N int, T []int, M int, P []int, X []int) {
	for i := 0; i < M; i++ {
		ans := 0
		for j := 0; j < N; j++ {
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)
	T := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &T[i])
	}

	var M int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &M)
	P := make([]int, M)
	X := make([]int, M)
	for i := 0; i < M; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &P[i])
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &X[i])
	}

	solve(N, T, M, P, X)
}

