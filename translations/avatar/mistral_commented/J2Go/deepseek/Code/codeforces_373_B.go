package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var ans int64 = 0

// Function to calculate the sum of digits from position 'a' to the end
func get(a int64) int64 {
	var ret int64 = 0
	var now int64 = 1
	var t int64 = 1
	for {
		// Calculate the sum of digits from current position to the end
		if now*10 > a {
			ret += (a - now + 1) * t
			break
		}
		ret += now * 9 * t
		now *= 10
		t++
	}
	return ret
}

// Binary search function to find the position of the number that satisfies the condition
func binarySearch(k, l, r, x int64) int64 {
	// Base case: if the search range is empty, return -1
	if r >= l {
		mid := l + (r-l)/2
		// Check if the middle index is the answer and if it satisfies the condition
		if mid > ans && mid*k <= x {
			ans = mid
		}

		// Check if the middle index is the answer
		if k*mid == x {
			return mid
		}

		// Recursively search in the left subtree if the condition is not satisfied
		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		// Recursively search in the right subtree if the condition is not satisfied
		return binarySearch(k, mid+1, r, x)
	}

	// Base case: if the search range is empty, return -1
	return -1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var gen, st, tim int64
	fmt.Fscan(reader, &gen)
	fmt.Fscan(reader, &st)
	fmt.Fscan(reader, &tim)
	gen /= tim
	var beg, end int64 = st - 1, int64(math.Pow(10, 18))
	// Binary search to find the position of the number that satisfies the condition
	for {
		var med int64 = (beg + end) / 2 + 1
		if get(med)-get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		if beg == end {
			fmt.Fprintln(writer, beg-st+1)
			break
		}
	}
}
