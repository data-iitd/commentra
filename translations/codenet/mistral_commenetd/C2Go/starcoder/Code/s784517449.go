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
		}
		if key > A[mid] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return 0
}

func main() {
	var n, q, k, sum int
	var A []int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	for i := 0; i < n; i++ {
		var element int
		fmt.Fscan(reader, &element)
		A = append(A, element)
	}
	fmt.Fscan(reader, &q)
	for i := 0; i < q; i++ {
		fmt.Fscan(reader, &k)
		if binarySearch(A, k) == 1 {
			sum++
		}
	}
	fmt.Println(sum)
}

