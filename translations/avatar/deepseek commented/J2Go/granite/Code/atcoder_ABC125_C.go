
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	N int
	A []int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		N, _ = strconv.Atoi(scanner.Text())
	}
	A = make([]int, N)
	for i := 0; i < N; i++ {
		if scanner.Scan() {
			A[i], _ = strconv.Atoi(scanner.Text())
		}
	}

	L := make([]int, N)
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	R := make([]int, N)
	R[N-1] = A[N-1]
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	answer := max(L[N-2], R[1])
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}

	fmt.Println(answer)
}

func gcd(a, b int) int {
	var tmp int
	if b > a {
		tmp = a
		a = b
		b = tmp
	}
	if b == 0 {
		return a
	}
	r := -1
	for r!= 0 {
		r = a % b
		a = b
		b = r
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

