
package main

import (
	"fmt"
)

func getNum() int {
	var n int
	fmt.Scan(&n)
	return n
}

func putNum(n int) {
	fmt.Printf("%d", n)
}

func CountingSort(A []int, B []int, k int, len int) {
	var i int
	var count [MAX_Ai]int
	for i = 0; i < len; i++ {
		count[A[i]]++
	}
	for i = 1; i < k; i++ {
		count[i] += count[i-1]
	}
	for i = len - 1; i >= 0; i-- {
		B[count[A[i]]-1] = A[i]
		count[A[i]]--
	}
}

func main() {
	var i int
	var n int
	var len int
	var k int
	var A [MAX_N]int
	var B [MAX_N]int
	n = getNum()
	len = n
	k = MAX_Ai
	for i = 0; i < len; i++ {
		A[i] = getNum()
	}
	CountingSort(A, B, k, len)
	for i = 0; i < len; i++ {
		putNum(B[i])
	}
}

