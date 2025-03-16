
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var A []int
	var q int
	var k int
	var sum int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	A = make([]int, n)
	for i := 0; i < n; i++ {
		if scanner.Scan() {
			A[i], _ = strconv.Atoi(scanner.Text())
		}
	}
	if scanner.Scan() {
		q, _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < q; i++ {
		if scanner.Scan() {
			k, _ = strconv.Atoi(scanner.Text())
		}
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

