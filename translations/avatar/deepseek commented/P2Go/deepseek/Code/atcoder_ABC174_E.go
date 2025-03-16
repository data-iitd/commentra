package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// check checks if it's possible to distribute the elements of lis such that each element is at most mid and the total number of operations does not exceed k.
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of elements (n) and the initial value of k from input.
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	// Read the list of integers from input.
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		lis[i], _ = strconv.Atoi(scanner.Text())
	}

	// Initialize the search range with 1 and the maximum value in the list.
	a, b := 1, lis[0]
	for _, i := range lis {
		if i > b {
			b = i
		}
	}

	// Initialize the answer with the maximum value in the list.
	ans := b

	// Perform a binary search to find the maximum value of mid that satisfies the condition.
	for a <= b {
		mid := (a + b) / 2 // Calculate the middle value of the current search range.
		if check(lis, k, mid) {
			ans = mid // Update the answer to the current mid value.
			b = mid - 1 // Adjust the upper bound of the search range.
		} else {
			a = mid + 1 // Adjust the lower bound of the search range.
		}
	}

	// Print the result, which is the maximum value of mid that satisfies the condition.
	fmt.Println(ans)
}
