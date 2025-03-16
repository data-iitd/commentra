package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MAX_N    = 2000001
	MAX_Ai   = 10001
	STR_SIZE = 10000010
)

var (
	A    [MAX_N]int
	B    [MAX_N]int
	str  [STR_SIZE]byte
	p    *byte
)

func getNum() int {
	n := 0
	for *p >= '0' && *p <= '9' {
		n = n*10 + int(*p-'0')
		p++
	}
	p++
	return n
}

func putNum(n int) {
	if n < 10 {
		PutChar(byte('0' + n))
		return
	}
	d := n / 10
	if d > 0 {
		putNum(d)
	}
	PutChar(byte('0' + (n - (d * 10))))
}

func PutChar(c byte) {
	*p = c
	p++
}

func CountingSort(A []int, B []int, k int, len int) {
	C := make([]int, MAX_Ai)
	for j := 0; j < len; j++ {
		C[A[j]]++
	}
	for i := 1; i <= k; i++ {
		C[i] += C[i-1]
	}
	for j := len - 1; j >= 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadBytes(byte('\n'))

	n := getNum()
	for i := 0; i < n; i++ {
		A[i] = getNum()
	}

	CountingSort(A[:n], B[:n], MAX_Ai, n)

	p = &str[0]
	for i := 0; i < n-1; i++ {
		putNum(B[i])
		PutChar(' ')
	}
	putNum(B[n-1])
	PutChar('\0')

	fmt.Print(string(str[:p-&str[0]]))
}

