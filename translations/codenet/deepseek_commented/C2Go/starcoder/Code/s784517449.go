<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func binarySearch(A []int, key int) int {
	left := 0
	right := len(A) - 1
	mid := 0
	for left <= right {
		mid = (left + right) / 2
		if key == A[mid] {
			return 1
		} else if key > A[mid] {
			left = mid + 1
		} else if key < A[mid] {
			right = mid - 1
		}
	}
	return 0
}

func main() {
	var n, q, k int
	var A []int
	var sum int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var tmp int
		fmt.Scanf("%d", &tmp)
		A = append(A, tmp)
	}
	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &k)
		if binarySearch(A, k) == 1 {
			sum++
		}
	}
	fmt.Printf("%d\n", sum)
}

