package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	var res int = 0

	// Define the recursive function to generate sequences
	var rec func([]int)
	rec = func(A []int) {
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			if ans > res {
				res = ans
			}
			return
		}
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}
		for i := lastMax; i <= M; i++ {
			rec(append(A, i))
		}
	}

	rec([]int{})
	fmt.Println(res)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	M, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	Q, _ := strconv.Atoi(scanner.Text())

	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)

	for i := 0; i < Q; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		c[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		d[i], _ = strconv.Atoi(scanner.Text())
	}

	solve(N, M, Q, a, b, c, d)
}

