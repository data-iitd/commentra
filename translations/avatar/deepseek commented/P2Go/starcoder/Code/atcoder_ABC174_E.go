package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// check checks if it's possible to distribute the elements of lis
// such that each element is at most mid and the total number of operations
// does not exceed k.
func check(lis []int, k, mid int) bool {
	for _, i := range lis {
		if i%mid == 0 {
			k++
		}
		k -= i / mid
	}
	return k >= 0
}

func main() {
	// Read the number of elements (n) and the initial value of k from input.
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &k)

	// Read the list of integers from input.
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &lis[i])
	}

	// Initialize the search range with 1 and the maximum value in the list.
	a, b := 1, lis[0]
	for i := 1; i < n; i++ {
		if lis[i] > b {
			b = lis[i]
		}
	}

	// Initialize the answer with the maximum value in the list.
	ans := b

	// Perform a binary search to find the maximum value of mid that satisfies the condition.
	for a <= b {
		mid := (a + b) / 2
		if check(lis, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}

	// Print the result, which is the maximum value of mid that satisfies the condition.
	fmt.Println(ans)
}

