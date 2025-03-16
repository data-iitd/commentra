```go
package main

import (
	"fmt"
	"sort"
)

func main() {
	var A [4]int
	fmt.Scan(&A[0], &A[1], &A[2], &A[3])
	if A[1] <= A[2] || A[3] <= A[0] {
		fmt.Println(0)
	} else {
		sort.Ints(A[:])
		fmt.Println(A[2] - A[1])
	}
}
