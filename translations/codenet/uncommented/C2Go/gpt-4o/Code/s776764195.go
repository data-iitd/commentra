package main

import (
	"fmt"
	"os"
)

const (
	MAX_N   = 2000001
	MAX_Ai  = 10001
	STR_SIZE = 10000010
)

var (
	A [MAX_N]int
	B [MAX_N]int
	str [STR_SIZE]byte
	p int
)

func getNum() int {
	n := 0
	for p < len(str) && str[p] >= '0' && str[p] <= '9' {
		n = n*10 + int(str[p]-'0')
		p++
	}
	p++ // Skip the space or newline after the number
	return n
}

func putNum(n int) {
	if n < 10 {
		str[p] = byte('0' + n)
		p++
		return
	}
	d := n / 10
	if d > 0 {
		putNum(d)
	}
	str[p] = byte('0' + (n - (d * 10)))
	p++
}

func CountingSort(A []int, B []int, k int, len int) {
	C := make([]int, MAX_Ai)
	for j := 1; j <= len; j++ {
		C[A[j]]++
	}
	for i := 1; i <= k; i++ {
		C[i] += C[i-1]
	}
	for j := len; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

func main() {
	n := 0
	// Read input from stdin
	n, _ = fmt.Fscan(os.Stdin, &str)
	p = 0
	n = getNum()
	for i := 1; i <= n; i++ {
		A[i] = getNum()
	}

	CountingSort(A[:], B[:], MAX_Ai, n)

	p = 0
	for i := 1; i < n; i++ {
		putNum(B[i])
		str[p] = ' '
		p++
	}
	putNum(B[n])
	str[p] = '\0'
	p++

	fmt.Print(string(str[:p]))
}

// <END-OF-CODE>
