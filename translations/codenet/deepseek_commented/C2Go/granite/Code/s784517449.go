
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 1000000
	var n int
	var A = make([]int, 0, initialCapacity)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	for i := 0; i < n; i++ {
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		A = append(A, k)
	}
	var q int
	scanner.Scan()
	q, _ = strconv.Atoi(scanner.Text())
	var sum int
	for i := 0; i < q; i++ {
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		if binarySearch(A, k) {
			sum++
		}
	}
	fmt.Println(sum)
}

func binarySearch(A []int, key int) bool {
	left := 0
	right := len(A)
	for left < right {
		mid := (left + right) / 2
		if key == A[mid] {
			return true
		} else if key > A[mid] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return false
}

// 