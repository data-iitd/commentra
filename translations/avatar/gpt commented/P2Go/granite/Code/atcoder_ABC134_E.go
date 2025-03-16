
package main

import (
	"bufio"
	"fmt"
	"os"
)

func binarySearch(key int) int {
	bad, good := -1, len(ans)
	for good-bad > 1 {
		mid := (bad + good) / 2
		if ans[mid][len(ans[mid])-1] < key {
			good = mid
		} else {
			bad = mid
		}
	}
	return good
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialCapacity = 100000
	ans := make([][]int, 0, initialCapacity)
	var N int
	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		idx := binarySearch(A)
		if idx == len(ans) {
			ans = append(ans, []int{A})
		} else {
			ans[idx] = append(ans[idx], A)
		}
	}
	fmt.Println(len(ans))
}

