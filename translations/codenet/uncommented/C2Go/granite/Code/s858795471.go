
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func search(A []int, n int, key int) bool {
	i := 0
	A[n] = key
	for A[i]!= key {
		i++
	}
	return i!= n
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 10000 + 1
	var n int
	fmt.Scan(&n)
	A := make([]int, initialCapacity)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	var q int
	fmt.Scan(&q)
	var sum int
	for i := 0; i < q; i++ {
		fmt.Scan(&n)
		if search(A, n, q) {
			sum++
		}
	}
	fmt.Println(sum)
}

