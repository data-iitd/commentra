
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX_N     = 2000001
	MAX_Ai    = 10001
	STR_SIZE  = 10000010
)

var (
	bufIn  = bufio.NewReader(os.Stdin)
	bufOut = bufio.NewWriter(os.Stdout)
)

func getNum() int {
	var n int
	for {
		b, _ := bufIn.ReadByte()
		if b >= '0' && b <= '9' {
			n = n*10 + int(b-'0')
		} else {
			break
		}
	}
	return n
}

func putNum(n int) {
	if n < 10 {
		bufOut.WriteByte('0' + byte(n))
	} else {
		putNum(n / 10)
		bufOut.WriteByte('0' + byte(n%10))
	}
}

func CountingSort(A, B []int, k, len int) {
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
	var (
		n int
		A = make([]int, MAX_N)
		B = make([]int, MAX_N)
	)
	bufIn.Read(bufIn.Bytes())
	n = getNum()
	for i := 1; i <= n; i++ {
		A[i] = getNum()
	}
	CountingSort(A, B, MAX_Ai, n)
	for i := 1; i < n; i++ {
		putNum(B[i])
		bufOut.WriteByte(' ')
	}
	putNum(B[n])
	bufOut.WriteByte('\n')
	bufOut.Flush()
}

// 