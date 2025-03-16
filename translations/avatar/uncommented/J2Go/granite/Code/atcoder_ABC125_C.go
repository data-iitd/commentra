
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var A []int

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	N := nextInt(sc)
	A = make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = nextInt(sc)
	}
	L := make([]int, N)
	R := make([]int, N)
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}
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
	tmp := a
	if b > a {
		tmp = b
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
	} else {
		return b
	}
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

