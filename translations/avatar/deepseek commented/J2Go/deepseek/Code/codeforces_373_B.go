package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

// Global variable to store the answer
var ans int64 = 0

// Helper function to calculate the sum of numbers based on a specific pattern
func get(a int64) int64 {
	var ret int64 = 0
	var now int64 = 1
	var t int64 = 1
	for {
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

// Binary search function to find the desired value
func binarySearch(k, l, r, x int64) int64 {
	if r >= l {
		mid := l + (r-l)/2
		if mid > ans && mid*k <= x {
			ans = mid
		}

		if k*mid == x {
			return mid
		}

		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		return binarySearch(k, mid+1, r, x)
	}

	return -1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var gen, st, tim int64
	fmt.Fscan(reader, &gen, &st, &tim)
	gen /= tim
	var beg, end int64 = st - 1, int64(math.Pow(10, 18))
	for {
		med := (beg + end) / 2 + 1
		if get(med) - get(st - 1) > gen {
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

